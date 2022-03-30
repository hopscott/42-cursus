/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fitting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/03/23 17:28:22 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	deg2rad(double degree)
{
	return (degree * (M_PI / 180));
}

void	find_origin_point(t_map *map, t_point **arr)
{
	int		i;
	t_point	*pt;

	i = 0;
	pt = arr[i];
	while (i < map->points)
	{
		if (arr[i]->px < pt->px)
			pt = arr[i];
		i++;
	}
	map->px_min = pt->px;
	i = 0;
	pt = arr[i];
	while (i < map->points)
	{
		if (arr[i]->py < pt->py)
			pt = arr[i];
		i++;
	}
	map->py_min = pt->py;
}

void	find_furthest_point(t_map *map, t_point **arr)
{
	int		i;
	t_point	*pt;

	i = 0;
	pt = arr[i];
	while (i < map->points)
	{
		if (arr[i]->px > pt->px)
			pt = arr[i];
		i++;
	}
	map->px_max = pt->px;
	i = 0;
	pt = arr[i];
	while (i < map->points)
	{
		if (arr[i]->py > pt->py)
			pt = arr[i];
		i++;
	}
	map->py_max = pt->py;
}

void	find_map_heights(t_map *map, t_point **arr)
{
	int		i;
	t_point	*pt;

	i = 0;
	pt = arr[i];
	while (i < map->points)
	{
		if (arr[i]->z < pt->z)
			pt = arr[i];
		i++;
	}
	map->z_min = pt->z;
	i = 0;
	pt = arr[i];
	while (i < map->points)
	{
		if (arr[i]->z > pt->z)
			pt = arr[i];
		i++;
	}
	map->z_max = pt->z;
}

void	fit_points_full_window(t_map *map, t_point **arr)
{
	double 	xdiff;
	double	ydiff;
	double	factor;
	double	xmove;
	double	ymove;

	find_origin_point(map, arr);
	find_furthest_point(map, arr);
	xdiff = map->px_max - map->px_min;
	ydiff = map->py_max - map->py_min;
	factor = 1;
	if ((xdiff > ydiff) && (xdiff != 0))
		factor = ((3 * WIDTH) / (4 * xdiff));
	else if ((ydiff > xdiff) && (ydiff != 0))
		factor = ((3 * HEIGHT) / (4 * ydiff));
	if (factor < 1)
		factor = 1;
	basic_zoom(map, map->zoom * factor);
	basic_rotate(map, map->alpha, map->beta, map->theta);
	find_origin_point(map, arr);
	find_furthest_point(map, arr);
	xmove = (WIDTH / 2) - ((map->px_max - map->px_min) / 2);
	ymove = (HEIGHT / 2) - ((map->py_max - map->py_min) / 2);
	map->dx += xmove;
	map->dy += ymove;
	basic_translate(map, xmove, ymove);
}
