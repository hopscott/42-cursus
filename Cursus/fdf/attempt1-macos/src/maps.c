/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/03/23 17:41:48 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	map_dimensions(int fd, t_map *map)
{
	int		rows;
	int		cols;
	uchar	*line;

	line = get_next_line(fd);
	if (!line)
		return (1);
	rows = 0;
	cols = ft_wordcount(line, ' ');
	while (line)
	{
		rows++;
		if (ft_wordcount(line, ' ') != cols)
		{
			free(line);
			return (1);
		}
		line = get_next_line(fd);
	}
	free(line);
	map->cols = cols;
	map->rows = rows;
	map->points = cols * rows;
	return (0);
}

void	parse_map_points(t_map *map, t_point **arr, int fd, int r)
{
	int		c;
	uchar	**row;
	uchar	*line;

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
		line = get_next_line(fd);
	}
	free(line);
}

t_map	*parse_map(char *path)
{
	t_map	*map;
	int		fd;
	int		err;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	fd = open(path, O_RDONLY);
	if (!fd)
		return (map);
	err = map_dimensions(fd, map);
	close(fd);
	if (err)
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

t_map	*build_map(char *path)
{
	t_map	*map;

	map = parse_map(path);
	if (!map->arr)
		return (map);
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
	return (map);
}
