/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/03/10 17:47:06 by swillis          ###   ########.fr       */
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

#include <stdio.h>

void	fit_points_full_window(t_map *map, t_point **arr)
{
	int		i;
	t_point	*pt;

	find_origin_point(map, arr);
	find_furthest_point(map, arr);
	printf(">[origin]> (%f, %f)\n", map->px_min, map->py_min);
	printf(">[max]> (%f, %f)\n", map->px_max, map->py_max);
	i = 0;
	while (i < map->points)
	{
		pt = arr[i];
		// pt->px = (pt->px - map->px_min) * (WIDTH / (map->px_max - map->px_min));
		// pt->py = (pt->py - map->py_min) * (HEIGHT / (map->py_max - map->py_min));
		pt->px += map->px_min;
		pt->py += map->py_min;
		// // NEED TO RECENTER AROUND ORIGIN
		// x -= (map->px_max - map->px_min) / 2;
		// y -= (map->py_max - map->py_min) / 2;
		// printf(">centered> (%f, %f)\n", x, y);
		// x *= WIDTH / (map->px_max - map->px_min);
		// y *= HEIGHT / (map->py_max - map->py_min);
		// printf(">scaled> (%f, %f)\n", x, y);
		i++;
	}
}

// // https://stackoverflow.com/questions/28607713/convert-3d-coordinates-to-2d-in-an-isometric-projection
// void	pixel_mapping_isometric(t_map *map, t_point **arr)
// {
// 	t_point	*pt;
// 	int		i;
// 	int		alpha;

// 	alpha = map->alpha;
// 	i = 0;
// 	while (i < map->points)
// 	{
// 		pt = arr[i];
// 		//pt->px = pt->x * cos(deg2rad(alpha)) + pt->y * cos(deg2rad(alpha + 120)) + pt->z * cos(deg2rad(alpha - 120));
// 		//pt->py = pt->x * sin(deg2rad(alpha)) + pt->y * sin(deg2rad(alpha + 120)) + pt->z * sin(deg2rad(alpha - 120));
// 		pt->px = pt->x * cos(deg2rad(alpha)) + pt->y * cos(deg2rad(alpha + 120)) + pt->z * cos(deg2rad(alpha - 120));
// 		pt->py = pt->x * sin(deg2rad(alpha)) + pt->y * sin(deg2rad(alpha + 120)) + pt->z * sin(deg2rad(alpha - 120));
// 		i++;
// 	}
// }
