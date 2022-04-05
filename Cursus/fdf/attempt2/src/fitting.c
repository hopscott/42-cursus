/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fitting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/04/01 17:36:21 by swillis          ###   ########.fr       */
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
	double	xdiff;
	double	ydiff;
	double	zoom;

	find_origin_point(map, arr);
	find_furthest_point(map, arr);
	xdiff = map->px_max - map->px_min;
	ydiff = map->py_max - map->py_min;
	zoom = 1;
	if (((WIDTH / xdiff) < (HEIGHT / ydiff)) && (xdiff != 0))
		zoom = ((9 * WIDTH) / (10 * xdiff));
	else if (((WIDTH / xdiff) > (HEIGHT / ydiff)) && (ydiff != 0))
		zoom = ((9 * HEIGHT) / (10 * ydiff));
	if (zoom < 1)
		zoom = 1;
	basic_zoom(map, (int)zoom);
	basic_rotate(map, map->alpha, map->beta, map->theta);
	find_origin_point(map, arr);
	find_furthest_point(map, arr);
	map->dx = (WIDTH / 2) - (((int)map->px_max + (int)map->px_min) / 2);
	map->dy = (HEIGHT / 2) - (((int)map->py_max + (int)map->py_min) / 2);
	basic_translate(map, map->dx, map->dy);
}
