/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:11 by swillis           #+#    #+#             */
/*   Updated: 2022/03/22 23:48:17 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
