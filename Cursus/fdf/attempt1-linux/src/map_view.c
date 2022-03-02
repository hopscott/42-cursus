/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/03/01 23:25:47 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double deg2rad(double degree)
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
		if (arr[i]->u < pt->u)
			pt = arr[i];
		i++;
	}
	map->u_min = pt->u;
	i = 0;
	pt = arr[i];
	while (i < map->points)
	{
		if (arr[i]->v < pt->v)
			pt = arr[i];
		i++;
	}
	map->v_min = pt->v;
}

void	find_furthest_point(t_map *map, t_point **arr)
{
	int		i;
	t_point	*pt;

	i = 0;
	pt = arr[i];
	while (i < map->points)
	{
		if (arr[i]->u > pt->u)
			pt = arr[i];
		i++;
	}
	map->u_max = pt->u;
	i = 0;
	pt = arr[i];
	while (i < map->points)
	{
		if (arr[i]->v > pt->v)
			pt = arr[i];
		i++;
	}
	map->v_max = pt->v;
}

void	fit_points_full_window(t_map *map, t_point **arr)
{
	int		i;
	t_point	*pt;

	find_origin_point(map, arr);
	find_furthest_point(map, arr);
	i = 0;
	while (i < map->points)
	{
		pt = arr[i];
		pt->u = (pt->u - map->u_min) * (HEIGHT / (map->u_max - map->u_min));
		pt->v = (pt->v - map->v_min) * (WIDTH / (map->v_max - map->v_min));
		i++;
	}
}

/*
// https://www.compuphase.com/axometr.htm
void	dimetric_map_points(t_map *map, t_point **arr)
{
	int		i;
	t_point	*pt;

	i = 0;
	while (i < map->points)
	{
		pt = arr[i];
		pt->x = (int) (pt->x * cos(deg2rad(7)) + ((pt->z * cos(deg2rad(42))) / 2));
		pt->y = (int) (pt->y + ((pt->z * sin(deg2rad(42))) / 2) - (pt->x * sin(deg2rad(7))));
		i++;
	}
}

void	isometric_map_points(t_map *map, t_point **arr)
{
	int		i;
	t_point	*pt;

	i = 0;
	while (i < map->points)
	{
		pt = arr[i];
	//	pt->x = (int) ((pt->x - pt->z) * cos(deg2rad(30)));
	//	pt->y = (int) (pt->y + (pt->x + pt->z) * sin(deg2rad(30)));
		pt->x = (int) ((pt->x - pt->z) * cos(deg2rad(30)));
		pt->y = (int) (pt->y + (pt->x + pt->z) * sin(deg2rad(40)));
		i++;
	}
}

*/