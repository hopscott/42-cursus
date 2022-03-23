/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:11 by swillis           #+#    #+#             */
/*   Updated: 2022/03/23 12:57:01 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham_plot(t_data *data, t_trace trace)
{
	while (1)
	{
		my_mlx_pixel_put(data, trace.x0, trace.y0, 0xFF0000);
		if ((trace.x0 == trace.x1) && (trace.y0 == trace.y1))
			break ;
		trace.e2 = 2 * trace.err;
		if (trace.e2 >= trace.dy)
		{
			if (trace.x0 == trace.x1)
				break ;
			trace.err += trace.dy;
			trace.x0 += trace.sx;
		}
		if (trace.e2 <= trace.dx)
		{
			if (trace.y0 == trace.y1)
				break ;
			trace.err += trace.dx;
			trace.y0 += trace.sy;
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
	bresenham_plot(data, trace);
}
