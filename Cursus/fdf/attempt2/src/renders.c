/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:11 by swillis           #+#    #+#             */
/*   Updated: 2022/04/01 18:20:22 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	rgb_colour(unsigned int r, unsigned int g, unsigned int b)
{
	return ((r << 16) + (g << 8) + b);
}

unsigned int	perc_colour(t_colour *c0, t_colour *c1, double p)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	red = c0->r * (1 - p) + c1->r * p;
	green = c0->g * (1 - p) + c1->g * p;
	blue = c0->b * (1 - p) + c1->b * p;
	return (rgb_colour(red, green, blue));
}

void	render_map(t_data *data, t_map *map)
{
	if ((fabs(map->theta) < 90) || (fabs(map->theta) > 270))
	{
		if (map->type == 0)
			trace_map_points(data, map, map->arr);
		if (map->type == 1)
			trace_map_lines(data, map, map->arr);
		if (map->type == 2)
			trace_map_gradients(data, map, map->arr);
	}
	else
	{
		if (map->type == 0)
			rev_trace_map_points(data, map, map->arr);
		if (map->type == 1)
			rev_trace_map_lines(data, map, map->arr);
		if (map->type == 2)
			rev_trace_map_gradients(data, map, map->arr);
	}
}
