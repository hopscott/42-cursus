/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/03/04 01:00:28 by swillis          ###   ########.fr       */
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
	int c;
	uchar **row;
	uchar *line;
	t_point *pt;

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

void reset_points(t_map *map, t_point **arr)
{
	t_point *pt;
	int i;

	i = 0;
	while (i < map->points)
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

void	vector_multiply(int a, int b[], int dst[])
{
    dst[0] = a * b[0];
    dst[1] = a * b[1];
    dst[2] = a * b[2];
}

void	vector_add(int a[], int b[], int dst[])
{
    dst[0] = a[0] + b[0];
    dst[1] = a[1] + b[1];
    dst[2] = a[2] + b[2];
}

// https://en.wikipedia.org/wiki/3D_projection#:~:text=A%203D%20projection%20(or%20graphical,capability%20on%20a%20simpler%20plane.
void	uv_mapping(t_map *map, t_plane *plane, t_point **arr)
{
	t_point *pt;
	int 	i;
	// int		tmp1[3];
	// int		tmp2[3];
	// int		tmp3[3];

	i = 0;
	while (i < map->points)
	{
		pt = arr[i];
		pt->u = vector_dot(plane->u, pt->xyz, 3);
		pt->v = vector_dot(plane->v, pt->xyz, 3);
		// https://forums.autodesk.com/t5/revit-api-forum/how-to-get-xyz-by-the-uv-on-surface/td-p/9788287
		// vector_multiply(pt->u, plane->u, tmp1);
		// vector_multiply(pt->v, plane->v, tmp2);
		// vector_add(tmp1, tmp2, tmp3);
		// vector_add(pt->xyz, tmp3, pt->xyz);
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

// https://stackoverflow.com/questions/18663755/how-to-convert-a-3d-point-on-a-plane-to-uv-coordinates
void	set_map_plane(t_map *map, int a, int b, int c)
{
	map->plane->a = a;
	map->plane->b = b;
	map->plane->c = c;
	map->plane->n[0] = map->plane->a;
	map->plane->n[1] = map->plane->b;
	map->plane->n[2] = map->plane->c;
	map->plane->u[0] = map->plane->n[1];
	map->plane->u[1] = -1 * map->plane->n[0];
	map->plane->u[2] = 0;
	if ((map->plane->n[0] == 0) && (map->plane->n[1] == 0))
	{
		map->plane->u[0] = 0;
		map->plane->u[1] = 0;
		map->plane->u[2] = map->plane->n[2];
	}
	normalise_arr_int(map->plane->u, 3);
	vector_cross(map->plane->n, map->plane->u, map->plane->v);
	uv_mapping(map, map->plane, map->arr);
}

t_map	*build_map(char *path)
{
	t_map	*map;

	map = parse_map(path);
	if (!map->arr)
		return (map);
	map->plane = malloc(sizeof(t_plane));
	if (!map->plane)
		return (map);
	reset_points(map, map->arr);
	return (map);
}
