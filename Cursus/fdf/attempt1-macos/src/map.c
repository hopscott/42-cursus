/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/02/24 21:36:55 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_map_cols(char *path)
{
	int		x;
	int		fd;
	uchar	*str;

	fd = open(path, O_RDONLY);
	if (!fd)
		return (-1);
	str = get_next_line(fd);
	close(fd);
	x = ft_wordcount(str, ' ');
	free(str);
	return (x);
}

int	fdf_map_rows(char *path)
{
	int	y;
	int	fd;

	fd = open(path, O_RDONLY);
	if (!fd)
		return (-1);
	y = 0;
	while (get_next_line(fd))
		y++;
	close(fd);
	return (y);
}

void	build_map_points(t_map map, t_point **arr, int fd)
{
	int		r;
	int		c;
	uchar	**row;
	uchar	*line;
	t_point	*pt;

	r = 0;
	line = get_next_line(fd);
	while (line && (r < map.rows))
	{
		row = ft_split(line, ' ');
		c = 0;
		while (c < map.cols)
		{
			pt = malloc(sizeof(t_point));
			if (!pt)
				return ;
			pt->x = c;
			pt->y = r;
			pt->z = ft_atoi(row[c]);
			arr[r * map.cols + c] = pt;
			c++;
		}
		r++;
		line = get_next_line(fd);
	}
	free(line);
	ft_freetbl(row, map.cols);
}

t_map	build_map(char *path)
{
	int		fd;
	t_map	map;

	map.cols = fdf_map_cols(path);
	map.rows = fdf_map_rows(path);
	map.points = map.cols * map.rows;
	map.arr_pt = malloc(sizeof(t_point *) * map.points);
	if (!map.arr_pt)
		return (map);
	fd = open(path, O_RDONLY);
	if (!fd)
		return (map);
	build_map_points(map, map.arr_pt, fd);
	close(fd);
	return (map);
}
