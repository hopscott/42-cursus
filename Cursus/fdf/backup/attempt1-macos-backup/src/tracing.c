/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:11 by swillis           #+#    #+#             */
/*   Updated: 2022/03/23 12:56:56 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int px, int py, int color)
{
	char	*dst;

	if (((0 <= px) && (px < WIDTH)) && ((0 <= py) && (py < HEIGHT)))
	{
		dst = data->addr + (py * data->line_length + \
								px * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	trace_map_points(t_data *data, t_map *map, t_point **arr)
{
	int		i;
	t_point	*pt;

	i = 0;
	while (i < map->points)
	{
		pt = arr[i];
		if (pt->z == 0)
			my_mlx_pixel_put(data, (int)pt->px, (int)pt->py, 0xFFFFFF);
		else
			my_mlx_pixel_put(data, (int)pt->px, (int)pt->py, 0x0000FF);
		i++;
	}
}

void	bresenham_lowplot(t_data *data, t_trace trace)
{
	trace.dx = trace.x1 - trace.x0;
	trace.dy = trace.y1 - trace.y0;
	trace.sx = 1;
	trace.sy = 1;
	if (trace.dy < 0)
	{
		trace.sy = -1;
		trace.dy = abs(trace.dy);
	}
	trace.param = (2 * trace.dy) - trace.dx;
	while (trace.x0 <= trace.x1)
	{
		my_mlx_pixel_put(data, trace.x0, trace.y0, 0xFF0000);
		if (trace.param > 0)
		{
			trace.y0 += trace.sy;
			trace.param += 2 * (trace.dy - trace.dx);
		}
		else
			trace.param += 2 * trace.dy;
		trace.x0 += trace.sx;
	}
}

void	bresenham_highplot(t_data *data, t_trace trace)
{
	trace.dx = trace.x1 - trace.x0;
	trace.dy = trace.y1 - trace.y0;
	trace.sx = 1;
	trace.sy = 1;
	if (trace.dx < 0)
	{
		trace.sx = -1;
		trace.dx = abs(trace.dx);
	}
	trace.param = (2 * trace.dx) - trace.dy;
	while (trace.y0 <= trace.y1)
	{
		my_mlx_pixel_put(data, trace.x0, trace.y0, 0xFF0000);
		if (trace.param > 0)
		{
			trace.x0 += trace.sx;
			trace.param += 2 * (trace.dx - trace.dy);
		}
		else
			trace.param += 2 * trace.dx;
		trace.y0 += trace.sy;
	}
}

void	swap_trace_points(t_trace trace, t_point *p0, t_point *p1)
{
	trace.x0 = (int)p1->px;
	trace.y0 = (int)p1->py;
	trace.x1 = (int)p0->px;
	trace.y1 = (int)p0->py;
}

// https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
void	bresenham_trace(t_data *data, t_point *p0, t_point *p1)
{
	t_trace	trace;

	trace.x0 = (int)p0->px;
	trace.y0 = (int)p0->py;
	trace.x1 = (int)p1->px;
	trace.y1 = (int)p1->py;
	if (abs((int)p1->py - (int)p0->py) < abs((int)p1->px - (int)p0->px))
	{
		if ((int)p0->px > (int)p1->px)
			swap_trace_points(trace, p0, p1);
		bresenham_lowplot(data, trace);
	}
	else
	{
		if ((int)p0->py > (int)p1->py)
			swap_trace_points(trace, p0, p1);
		bresenham_highplot(data, trace);
	}
}

void	trace_map_lines(t_data *data, t_map *map, t_point **arr)
{
	int		i;
	t_point	*p1;
	t_point	*p2;
	t_point	*p3;

	i = 0;
	while (i + 1 < map->points)
	{
		p1 = arr[i];
		p2 = arr[i + 1];
		if (p2->col != 0)
			bresenham_trace(data, map, p1, p2);
		i++;
	}
	i = 0;
	while (i + map->cols < map->points)
	{
		p1 = arr[i];
		p3 = arr[i + map->cols];
		bresenham_trace(data, map, p1, p3);
		i++;
	}
}
*/
