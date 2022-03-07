/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:11 by swillis           #+#    #+#             */
/*   Updated: 2022/03/03 17:32:01 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void my_mlx_pixel_put(t_data *data, int u, int v, int color)
{
	char *dst;

	// Issue here with pixel == height or width
	//ft_printf(">> (%d, %d)\n", u, v);
	if (((0 <= u) && (u < HEIGHT)) && ((0 <= v) && (v < WIDTH)))
	{
		dst = data->addr + (v * data->line_length + u * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void trace_map_points(t_data *data, t_map *map, t_point **arr)
{
	int i;
	t_point *pt;

	i = 0;
	while (i < map->points)
	{
		pt = arr[i];
		if (pt->height == 0)
			my_mlx_pixel_put(data, pt->u, pt->v, 0xFFFFFF);
		else
			my_mlx_pixel_put(data, pt->u, pt->v, 0x0000FF);
		i++;
	}
}

// https://personal.math.ubc.ca/~cass/courses/m308-02b/projects/puhalovic/#alldirections
// https://stackoverflow.com/questions/62651042/how-to-implement-bresenhams-line-algorithm-in-c-when-trying-to-draw-a-line-in-b
void bresenham_trace(t_data *img, t_point *p1, t_point *p2)
{
	// https://medium.com/geekculture/bresenhams-line-drawing-algorithm-2e0e953901b3
	// case 0 = x1 < x2
	// case 1 = x1 > x2
	int sx;
	int sy;
	int dx;
	int dy;
	int err;

	dx = abs(p2->u - p1->u);
	dy = abs(p2->v - p1->v);
	sx = 1;
	if (p1->u > p2->u)
		sx = -1;
	sy = 1;
	if (p1->v > p2->v)
		sy = -1;
	err = dx / 2;
	if (dx < dy)
		err = dy / 2;

	int x = p1->u;
	int y = p1->v;
	if (dx == 0)
	{
		while (y != p2->v)
		{
			my_mlx_pixel_put(img, x, y, 0xFF0000);
			if (err > -dx)
			{
				err -= dy;
				x += sx;
			}
			if (err < dy)
			{
				err += dx;
				y += sy;
			}
		}
	}
	if (dy == 0)
	{
		while (x != p2->u)
		{
			my_mlx_pixel_put(img, x, y, 0xFF0000);
			if (err > -dx)
			{
				err -= dy;
				x += sx;
			}
			if (err < dy)
			{
				err += dx;
				y += sy;
			}
		}
	}
	else
	{
		while ((x != p2->u) && (y != p2->v))
		{
			my_mlx_pixel_put(img, x, y, 0xFF0000);
			if (err > -dx)
			{
				err -= dy;
				x += sx;
			}
			if (err < dy)
			{
				err += dx;
				y += sy;
			}
		}
	}
	my_mlx_pixel_put(img, x, y, 0xFF0000);
}

void trace_map_lines(t_data *data, t_map *map, t_point **arr)
{
	int i;
	t_point *p1;
	t_point *p2;
	t_point *p3;

	i = 0;
	while (i + 1 < map->points)
	{
		p1 = arr[i];
		p2 = arr[i + 1];
		if (p2->col != 0)
			bresenham_trace(data, p1, p2);
		i++;
	}
	i = 0;
	while (i + map->cols < map->points)
	{
		p1 = arr[i];
		p3 = arr[i + map->cols];
		bresenham_trace(data, p1, p3);
		i++;
	}
}
