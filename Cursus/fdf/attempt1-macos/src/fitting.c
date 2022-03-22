/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fitting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/03/22 23:53:30 by swillis          ###   ########.fr       */
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

// TODO
void	fit_points_full_window(t_map *map, t_point **arr)
{
	find_origin_point(map, arr);
	find_furthest_point(map, arr);
}
