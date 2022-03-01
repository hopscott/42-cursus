/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/03/01 22:49:09 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int fdf_map_cols(char *path)
{
	int x;
	int fd;
	uchar *str;

	fd = open(path, O_RDONLY);
	if (!fd)
		return (-1);
	str = get_next_line(fd);
	close(fd);
	x = ft_wordcount(str, ' ');
	free(str);
	return (x);
}

int fdf_map_rows(char *path)
{
	int y;
	int fd;

	fd = open(path, O_RDONLY);
	if (!fd)
		return (-1);
	y = 0;
	while (get_next_line(fd))
		y++;
	close(fd);
	return (y);
}

void parse_map(t_map map, t_point **arr, int fd)
{
	int r;
	int c;
	uchar **row;
	uchar *line;
	t_point *pt;

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
				return;
			pt->col = c;
			pt->row = r;
			pt->height = ft_atoi(row[c]);
			arr[r * map.cols + c] = pt;
			c++;
		}
		r++;
		line = get_next_line(fd);
	}
	free(line);
	ft_freetbl(row, map.cols);
}

void reset_points(t_map map, t_point **arr)
{
	t_point *pt;
	int i;

	i = 0;
	while (i < map.points)
	{
		pt = arr[i];
		pt->xyz[0] = pt->col;
		pt->xyz[1] = pt->row;
		pt->xyz[2] = pt->height;
		i++;
	}
}

int	max_arr_int(int arr[], int len)
{
	int	i;
	int	max;

	i = 0;
	max = arr[i];
	while (i < len)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

void	normalise_arr_int(int arr[], int len)
{
	int	i;
	int	max;

	max = max_arr_int(arr, 3);
	i = 0;
	while (i < len)
	{
		arr[i] /= max;
		i++;
	}
}

int	vector_dot(int a[], int b[], int len)
{
	int	dot;
	int	i;

	i = 0;
	dot = 0;
	while (i < len)
	{
		dot += a[i] * b[i];
		i++;
	}
	return (dot);
}

void	vector_cross(int a[], int b[], int dst[])
{
	int	cross[3];

    cross[0] = a[1] * b[2] - a[2] * b[1];
    cross[1] = a[2] * b[0] - a[0] * b[2];
    cross[2] = a[0] * b[1] - a[1] * b[0];
	dst[0] = cross[0];
	dst[1] = cross[1];
	dst[2] = cross[2];
}

void uv_mapping(t_map map, t_plane *plane, t_point **arr)
{
	t_point *pt;
	int 	i;

	i = 0;
	while (i < map.points)
	{
		pt = arr[i];
		pt->u = vector_dot(plane->u, pt->xyz, 3);
		pt->v = vector_dot(plane->v, pt->xyz, 3);
		i++;
	}
}

t_map build_map(char *path)
{
	int		fd;
	t_map	map;

	// map properties
	map.cols = fdf_map_cols(path);
	map.rows = fdf_map_rows(path);
	map.points = map.cols * map.rows;

	// parse map
	map.arr = malloc(sizeof(t_point *) * map.points);
	if (!map.arr)
		return (map);
	fd = open(path, O_RDONLY);
	if (!fd)
		return (map);
	parse_map(map, map.arr, fd);
	close(fd);

	// setup eqn xyz plane
	map.plane = malloc(sizeof(t_plane));
	map.plane->a = 1;
	map.plane->b = 1;
	map.plane->c = 1;
	map.plane->d = 0;

	// https://stackoverflow.com/questions/18663755/how-to-convert-a-3d-point-on-a-plane-to-uv-coordinates
	
	// build up n vector
	map.plane->n[0] = map.plane->a;
	map.plane->n[1] = map.plane->b;
	map.plane->n[2] = map.plane->c;

	// build up u vector
	map.plane->u[0] = map.plane->n[1];
	map.plane->u[1] = -1 * map.plane->n[0];
	map.plane->u[2] = 0;
	if ((map.plane->n[0] == 0) && (map.plane->n[1] == 0))
	{
		map.plane->u[0] = 0;
		map.plane->u[1] = 0;
		map.plane->u[2] = map.plane->n[2];
	}
	normalise_arr_int(map.plane->u, 3);

	// build up v vector
	map.plane->v[0] = 0;
	map.plane->v[1] = 0;
	map.plane->v[2] = 0;
	vector_cross(map.plane->n, map.plane->u, map.plane->v);

	// setup points
	reset_points(map, map.arr);
	uv_mapping(map, map.plane, map.arr);

	return (map);
}
