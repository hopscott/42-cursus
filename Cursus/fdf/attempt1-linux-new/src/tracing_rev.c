/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing_rev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:12:46 by swillis           #+#    #+#             */
/*   Updated: 2022/04/01 18:18:37 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rev_trace_map_points(t_data *data, t_map *map, t_point **arr)
{
	int		i;
	t_point	*pt;

	i = map->points - 1;
	while (i >= 0)
	{
		pt = arr[i];
		my_mlx_pixel_put(data, (int)pt->px, (int)pt->py, \
										rgb_colour(255, 255, 255));
		i--;
	}
}

void	rev_trace_map_lines(t_data *data, t_map *map, t_point **arr)
{
	int		i;
	t_point	*p1;
	t_point	*p2;
	t_point	*p3;

	i = map->points - 1;
	while (i - 1 >= 0)
	{
		p1 = arr[i - 1];
		p2 = arr[i];
		if ((i) % map->cols != 0)
			bresenham_trace(data, p1, p2);
		i--;
	}
	i = map->points - 1;
	while (i - map->cols >= 0)
	{
		p1 = arr[i - map->cols];
		p3 = arr[i];
		bresenham_trace(data, p1, p3);
		i--;
	}
}

void	rev_trace_map_gradients(t_data *data, t_map *map, t_point **arr)
{
	int		i;
	t_point	*p1;
	t_point	*p2;
	t_point	*p3;

	i = map->points - 1;
	while (i - 1 >= 0)
	{
		p1 = arr[i - 1];
		p2 = arr[i];
		if ((i) % map->cols != 0)
			bresenham_trace_gradient(data, p1, p2);
		i--;
	}
	i = map->points - 1;
	while (i - map->cols >= 0)
	{
		p1 = arr[i - map->cols];
		p3 = arr[i];
		bresenham_trace_gradient(data, p1, p3);
		i--;
	}
}
