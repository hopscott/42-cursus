/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:11 by swillis           #+#    #+#             */
/*   Updated: 2022/03/23 18:03:02 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	rgb_colour(unsigned int r, unsigned int g, unsigned int b)
{
	return ((r << 16) + (g << 8) + b);
}

unsigned int	perc_colour(t_trace t, unsigned int p)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	red = t.r0 * ((100 - p) / 100) + t.r1 * (p / 100);
	green = t.g0 * ((100 - p) / 100) + t.g1 * (p / 100);
	blue = t.b0 * ((100 - p) / 100) + t.b1 * (p / 100);
	return (rgb_colour(red, green, blue));
}

void	bresenham_plot_basic(t_data *data, t_trace t)
{
	while (1)
	{
		my_mlx_pixel_put(data, t.x0, t.y0, perc_colour(t, 0));
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

void	bresenham_plot(t_data *data, t_trace t, unsigned int perc)
{
	while (1)
	{
		perc = t.z0;
		if (data->map->z_max - data->map->z_min != 0)
			perc /= (data->map->z_max - data->map->z_min);
		my_mlx_pixel_put(data, t.x0, t.y0, perc_colour(t, perc));
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
		t.z0 += (t.z1 - t.z0) / t.steps;
	}
}

void	bresenham_trace(t_data *data, t_point *p0, t_point *p1)
{
	t_trace	trace;

	trace.x0 = (int)p0->px;
	trace.y0 = (int)p0->py;
	trace.z0 = (int)p0->z;
	trace.x1 = (int)p1->px;
	trace.y1 = (int)p1->py;
	trace.z1 = (int)p1->z;
	trace.dx = abs(trace.x1 - trace.x0);
	trace.sx = 1;
	if (trace.x0 > trace.x1)
		trace.sx = -1;
	trace.dy = -1 * abs(trace.y1 - trace.y0);
	trace.sy = 1;
	if (trace.y0 > trace.y1)
		trace.sy = -1;
	trace.err = trace.dx + trace.dy;
	trace.r0 = 255;
	trace.g0 = 0;
	trace.b0 = 0;
	trace.r1 = 255;
	trace.g1 = 255;
	trace.b1 = 0;
	bresenham_plot_basic(data, trace);
	// bresenham_plot(data, trace, 0);
}
