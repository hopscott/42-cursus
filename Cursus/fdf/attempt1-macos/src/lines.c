/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:11 by swillis           #+#    #+#             */
/*   Updated: 2022/03/24 17:29:01 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham_plot_basic(t_data *data, t_colour *c, t_trace t)
{
	while (1)
	{
		my_mlx_pixel_put(data, t.x0, t.y0, rgb_colour(c->r, c->g, c->b));
		if ((t.x0 == t.x1) && (t.y0 == t.y1))
			break ;
		t.e2 = 2 * t.err;
		if (t.e2 >= t.dy)
		{
			if (t.x0 == t.x1)
				break ;
			t.err += t.dy;
			t.x0 += t.sx;
		}
		if (t.e2 <= t.dx)
		{
			if (t.y0 == t.y1)
				break ;
			t.err += t.dx;
			t.y0 += t.sy;
		}
	}
}

void	bresenham_trace(t_data *data, t_point *p0, t_point *p1)
{
	t_trace	trace;

	trace.x0 = (int)p0->px;
	trace.y0 = (int)p0->py;
	trace.x1 = (int)p1->px;
	trace.y1 = (int)p1->py;
	trace.dx = abs(trace.x1 - trace.x0);
	trace.sx = 1;
	if (trace.x0 > trace.x1)
		trace.sx = -1;
	trace.dy = -1 * abs(trace.y1 - trace.y0);
	trace.sy = 1;
	if (trace.y0 > trace.y1)
		trace.sy = -1;
	trace.err = trace.dx + trace.dy;
	bresenham_plot_basic(data, data->map->c0, trace);
}

int	bresenham_steps(t_trace t)
{
	int	steps;

	steps = 1;
	while (1)
	{
		if ((t.x0 == t.x1) && (t.y0 == t.y1))
			break ;
		t.e2 = 2 * t.err;
		if (t.e2 >= t.dy)
		{
			if (t.x0 == t.x1)
				break ;
			t.err += t.dy;
			t.x0 += t.sx;
		}
		if (t.e2 <= t.dx)
		{
			if (t.y0 == t.y1)
				break ;
			t.err += t.dx;
			t.y0 += t.sy;
		}
		steps++;
	}
	return (steps);
}

void	bresenham_plot(t_data *data, t_colour *c0, t_colour *c1, t_trace t)
{
	while (1)
	{
		my_mlx_pixel_put(data, t.x0, t.y0, perc_colour(c0, c1, t.h0));
		if ((t.x0 == t.x1) && (t.y0 == t.y1))
			break ;
		t.e2 = 2 * t.err;
		if (t.e2 >= t.dy)
		{
			if (t.x0 == t.x1)
				break ;
			t.err += t.dy;
			t.x0 += t.sx;
		}
		if (t.e2 <= t.dx)
		{
			if (t.y0 == t.y1)
				break ;
			t.err += t.dx;
			t.y0 += t.sy;
		}
		t.h0 += (t.h1 - t.h0) / t.steps;
	}
}

void	bresenham_trace_gradient(t_data *data, t_point *p0, t_point *p1)
{
	t_trace	trace;

	trace.x0 = (int)p0->px;
	trace.y0 = (int)p0->py;
	trace.x1 = (int)p1->px;
	trace.y1 = (int)p1->py;
	trace.dx = abs(trace.x1 - trace.x0);
	trace.sx = 1;
	if (trace.x0 > trace.x1)
		trace.sx = -1;
	trace.dy = -1 * abs(trace.y1 - trace.y0);
	trace.sy = 1;
	if (trace.y0 > trace.y1)
		trace.sy = -1;
	trace.err = trace.dx + trace.dy;
	trace.h0 = p0->z - data->map->z_min;
	if ((data->map->z_max - data->map->z_min) != 0)
		trace.h0 /= (data->map->z_max - data->map->z_min);
	trace.h1 = p1->z - data->map->z_min;
	if ((data->map->z_max - data->map->z_min) != 0)
		trace.h1 /= (data->map->z_max - data->map->z_min);
	trace.steps = bresenham_steps(trace);
	bresenham_plot(data, data->map->c0, data->map->c1, trace);
}
