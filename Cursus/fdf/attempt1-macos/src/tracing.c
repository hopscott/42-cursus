/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:11 by swillis           #+#    #+#             */
/*   Updated: 2022/03/07 01:19:13 by swillis          ###   ########.fr       */
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
		if (pt->height == 0)
			my_mlx_pixel_put(data, pt->px, pt->py, 0xFFFFFF);
		else
			my_mlx_pixel_put(data, pt->px, pt->py, 0x0000FF);
		i++;
	}
}

void	bresenham_plot(t_data *data, t_pixel start, t_pixel end)
{
	int	dx;
	int	dy;
	int	d;
	int	inc_e;
	int	inc_ne;

	dx = end.x - start.x;
	dy = end.y - start.y;
	inc_e = 2 * dy;
	inc_ne = 2 * dy - 2 * dx;
	d = 2 * dy - dx;
	while (start.x <= end.x)
	{
		my_mlx_pixel_put(data, start.x, start.y, 0xFF0000);
		if (d <= 0)
			d += inc_e;
		else
		{
			d += inc_ne;
			start.y += 1;
			if (dy < 0)
				start.y += -1;
		}
		start.x += 1;
	}
}

//https://webcache.googleusercontent.com/search?q=cache:MTVvqc2k2ssJ:https://www.geeksforgeeks.org/illustration-for-tracing-all-the-8-octaves-in-bresenhams-line-algorithm/+&cd=2&hl=en&ct=clnk&gl=fr
void	bresenham_trace(t_data *data, t_point *p1, t_point *p2)
{
	double	m;
	t_pixel	start;
	t_pixel	end;

	start.x = p1->px;
	start.y = p1->py;
	end.x = p2->px;
	end.y = p2->py;
	if ((end.x - start.x) == 0)
		return ;
	m = ((end.y - start.y) / (end.x - start.x));
	if ((end.x - start.x) < 0)
	{
		start.x = p2->px;
		start.y = p2->py;
		end.x = p1->px;
		end.y = p1->py;
	}
	if (m > 1)
	{
		start.x = p1->py;
		start.y = p1->px;
		end.x = p2->py;
		end.y = p2->px;
	}
	bresenham_plot(data, start, end);
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
