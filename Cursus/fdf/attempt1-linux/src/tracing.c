/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:11 by swillis           #+#    #+#             */
/*   Updated: 2022/02/25 22:09:28 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char *dst;

	if (((0 <= x) && (x <= WIDTH)) && ((0 <= y) && (y <= HEIGHT)))
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void trace_map_points(t_data *img, t_map *map)
{
	int i;
	t_point *pt;

	i = 0;
	while (i < map->points)
	{
		pt = map->arr_pt[i];
		if (pt->z == 0)
			my_mlx_pixel_put(img, pt->x, pt->y, 0xFFFFFF);
		else
			my_mlx_pixel_put(img, pt->x, pt->y, 0x0000FF);
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

	dx = abs(p2->x - p1->x);
	dy = abs(p2->y - p1->y);
	sx = 1;
	if (p1->x > p2->x)
		sx = -1;
	sy = 1;
	if (p1->y > p2->y)
		sy = -1;
	err = dx / 2;
	if (dx < dy)
		err = dy / 2;

	int x = p1->x;
	int y = p1->y;
	if (dx == 0)
	{
		while (y != p2->y)
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
		while (x != p2->x)
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
		while ((x != p2->x) && (y != p2->y))
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

void trace_map_lines(t_data *img, t_map *map)
{
	int i;
	t_point *p1;
	t_point *p2;
	t_point *p3;

	i = 0;
	while (i + 1 < map->points)
	{
		p1 = map->arr_pt[i];
		p2 = map->arr_pt[i + 1];
		if (p2->c != 0)
			bresenham_trace(img, p1, p2);
		i++;
	}
	i = 0;
	while (i + map->cols < map->points)
	{
		p1 = map->arr_pt[i];
		p3 = map->arr_pt[i + map->cols];
		bresenham_trace(img, p1, p3);
		i++;
	}
}
