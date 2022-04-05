/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/04/05 13:40:04 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
int	map_dimensions(int fd, t_map *map)
{
	int		rows;
	t_uchar	*line;

	line = get_next_line(fd);
	if (!line)
		return (1);
	rows = 0;
	map->cols = ft_elemcount(line);
	while (line && (ft_elemcount(line) > 0))
	{
		rows++;
		if (ft_elemcount(line) != map->cols)
		{
			map->err_elem = ft_elemcount(line);
			free(line);
			return (rows);
		}
		free(line);
		line = get_next_line(fd);
		printf(">%s<", line);
	}
	map->rows = rows;
	map->points = map->cols * map->rows;
	return (0);
}

void	parse_map_points(t_map *map, t_point **arr, int fd, int r)
{
	int		c;
	t_uchar	**row;
	t_uchar	*line;

	line = get_next_line(fd);
	while (line && (r < map->rows))
	{
		row = ft_split(line, ' ');
		c = 0;
		while (c < map->cols)
		{
			arr[r * map->cols + c] = malloc(sizeof(t_point));
			if (!arr[r * map->cols + c])
				return (free_arr_points(map->arr, r * map->cols + c));
			arr[r * map->cols + c]->x = c;
			arr[r * map->cols + c]->y = r;
			arr[r * map->cols + c]->z = ft_atoi(row[c]);
			c++;
		}
		r++;
		ft_freetbl(row, map->cols);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

t_map	*parse_map(char *path)
{
	t_map	*map;
	int		fd;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	fd = open(path, O_RDONLY);
	if (!fd)
		return (map);
	map->err_row = map_dimensions(fd, map);
	close(fd);
	map->arr = NULL;
	if (map->err_row)
		return (map);
	map->arr = malloc(sizeof(t_point *) * map->points);
	if (!map->arr)
		return (map);
	fd = open(path, O_RDONLY);
	if (!fd)
		return (map);
	parse_map_points(map, map->arr, fd, 0);
	close(fd);
	if (!map->arr)
		return (map);
	return (map);
}

void	set_map_colours(t_map *map)
{
	t_colour	*c0;
	t_colour	*c1;

	map->c0 = malloc(sizeof(t_colour));
	if (!map->c0)
		return ;
	c0 = map->c0;
	c0->r = 255;
	c0->g = 0;
	c0->b = 0;
	map->c1 = malloc(sizeof(t_colour));
	if (!map->c1)
		return ;
	c1 = map->c1;
	c1->r = 255;
	c1->g = 255;
	c1->b = 0;
}

t_map	*build_map(char *path)
{
	t_map	*map;

	map = parse_map(path);
	if (!map->arr)
	{
		ft_printf("Map Dimensions ERROR - Line (%d) ", map->err_row);
		ft_printf("=> [%d] elements vs. previous lines [%d]\n", \
		map->err_elem, map->cols);
		return (map);
	}
	find_map_heights(map, map->arr);
	map->zoom = 1;
	basic_zoom(map, map->zoom);
	map->rx = init_matrix(3, 3);
	map->ry = init_matrix(3, 3);
	map->rz = init_matrix(3, 3);
	map->r = init_matrix(3, 3);
	if (!map->rx || !map->ry || !map->rz || !map->r)
		return (map);
	basic_rotate(map, 45.0, asin(tan(deg2rad(30))), 45.0);
	basic_translate(map, 0.0, 0.0);
	set_map_colours(map);
	map->type = 1;
	return (map);
}
