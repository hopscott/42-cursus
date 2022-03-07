/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/03/06 20:46:56 by swillis          ###   ########.fr       */
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
		if (arr[i]->bx < pt->bx)
			pt = arr[i];
		i++;
	}
	map->bx_min = pt->bx;
	i = 0;
	pt = arr[i];
	while (i < map->points)
	{
		if (arr[i]->by < pt->by)
			pt = arr[i];
		i++;
	}
	map->by_min = pt->by;
}

void	find_furthest_point(t_map *map, t_point **arr)
{
	int		i;
	t_point	*pt;

	i = 0;
	pt = arr[i];
	while (i < map->points)
	{
		if (arr[i]->bx > pt->bx)
			pt = arr[i];
		i++;
	}
	map->bx_max = pt->bx;
	i = 0;
	pt = arr[i];
	while (i < map->points)
	{
		if (arr[i]->by > pt->by)
			pt = arr[i];
		i++;
	}
	map->by_max = pt->by;
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
		pt->bx = (pt->bx - map->bx_min); //* (WIDTH / (map->bx_max - map->bx_min));
		pt->by = (pt->by - map->by_min); //* (HEIGHT / (map->by_max - map->by_min));
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