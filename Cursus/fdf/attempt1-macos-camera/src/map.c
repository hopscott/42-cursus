/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/03/06 22:18:17 by swillis          ###   ########.fr       */
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

t_map	*reset_points(t_map *map, t_point **arr)
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
	return (map);
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
	return (reset_points(map, map->arr));
}

// ==========================================================

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

// ==========================================================

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

// ==========================================================

void	set_camera_position(t_map *map, int x, int y, int z)
{
	map->camera->c[0] = x;
	map->camera->c[1] = y;
	map->camera->c[2] = z;
}

void	set_camera_angle(t_map *map, int x_deg, int y_deg, int z_deg)
{
	int	x;
	int	y;
	int	z;

	x = deg2rad(x_deg);
	y = deg2rad(y_deg);
	z = deg2rad(z_deg);
	map->camera->theta[0] = x;
	map->camera->theta[1] = y;
	map->camera->theta[2] = z;
}

// void	set_camera_orientation(t_map *map, int x, int y, int z)
// {
// 	map->camera->e[0] = x;
// 	map->camera->e[1] = y;
// 	map->camera->e[2] = z;
// }

void	set_point_vector(t_map *map, t_camera *cam, t_point **arr)
{
	t_point *pt;
	int 	i;
	int 	x;
	int 	y;
	int 	z;

	i = 0;
	while (i < map->points)
	{
		pt = arr[i];
		x = pt->xyz[0] - cam->c[0];
		y = pt->xyz[1] - cam->c[1];
		z = pt->xyz[2] - cam->c[2];
		pt->d[0] = cos(cam->theta[1]) * (sin(cam->theta[2]) * y + cos(cam->theta[2]) * x) - sin(cam->theta[1]) * z;
		// dy   =      sx              (    cy              z    +        sy             (sz                y   +   cz                x )) +     cx                 (      cz        y  -     sz               x)
		pt->d[1] = sin(cam->theta[0]) * (cos(cam->theta[1]) * z + sin(cam->theta[1]) * (sin(cam->theta[2]) * y + cos(cam->theta[2]) * x)) + cos(cam->theta[0]) * (cos(cam->theta[2]) * y - sin(cam->theta[2]) * x);
		// dz   =      cx              (    cy              z    +        sy             (sz                y   +   cz                x )) +     sx                 (      cz        y  -     sz               x)
		pt->d[2] = cos(cam->theta[0]) * (cos(cam->theta[1]) * z + sin(cam->theta[1]) * (sin(cam->theta[2]) * y + cos(cam->theta[2]) * x)) + sin(cam->theta[0]) * (cos(cam->theta[2]) * y - sin(cam->theta[2]) * x);
		i++;
	}
}

void	set_point_projection(t_map *map, t_point **arr, int zoom)
{
	t_point *pt;
	int 	i;
	int 	dx;
	int 	dy;
	int 	dz;

	i = 0;
	while (i < map->points)
	{
		pt = arr[i];
		dx = pt->d[0];
		dy = pt->d[1];
		dz = pt->d[2];
		ft_printf("> %d %d %d\n", pt->xyz[0], pt->xyz[1], pt->xyz[2]);
		ft_printf("> %d %d %d\n", dx, dy, dz);
		// pt->bx = (cam->e[2] / dz) * dx + cam->e[0];
		// pt->by = (cam->e[2] / dz) * dy + cam->e[1];
		pt->bx = (dx / dz) * zoom;
		pt->by = (dy / dz) * zoom;
		ft_printf(">> %d %d\n", pt->bx, pt->by);
		i++;
	}
}

// https://stackoverflow.com/questions/18663755/how-to-convert-a-3d-point-on-a-plane-to-uv-coordinates
t_map	*build_map(char *path)
{
	t_map	*map;

	map = parse_map(path);
	if (!map->arr)
		return (map);
	map->camera = malloc(sizeof(t_camera));
	if (!map->camera)
		return (map);
	set_camera_position(map, 1, 1, 1);
	set_camera_angle(map, 0, 0, 0);
	// set_camera_orientation(map, 0, 0, 0);
	set_point_vector(map, map->camera, map->arr);
	set_point_projection(map, map->arr, 5);
	return (map);
}
