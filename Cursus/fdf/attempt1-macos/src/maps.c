/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/03/07 01:06:11 by swillis          ###   ########.fr       */
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
	t_point	*pt;

	line = get_next_line(fd);
	while (line && (r < map->rows))
	{
		row = ft_split(line, ' ');
		c = 0;
		while (c < map->cols)
		{
			pt = malloc(sizeof(t_point));
			if (!pt)
				return (free_arr_points(map->arr, r * map->cols + c));
			pt->col = c;
			pt->row = r;
			pt->height = ft_atoi(row[c]);
			arr[r * map->cols + c] = pt;
			c++;
		}
		r++;
		line = get_next_line(fd);
	}
	ft_freetbl(row, map->cols);
	free(line);
}

void	reset_points(t_map *map, t_point **arr)
{
	t_point	*pt;
	int		i;

	i = 0;
	while (i < map->points)
	{
		pt = arr[i];
		pt->x = pt->col;
		pt->y = pt->row;
		pt->z = pt->height;
		i++;
	}
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
	reset_points(map, map->arr);
	map->alpha = 30;
	pixel_mapping_isometric(map, map->arr);
	return (map);
}
