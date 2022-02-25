/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/02/24 23:02:28 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double deg2rad(double degree)
{
    return (degree * (M_PI / 180));
}

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

void	space_map_points(t_map *map, t_point **arr)
{
	int		i;
	t_point	*pt;

	i = 0;
	while (i < map->points)
	{
		pt = arr[i];
		pt->x = (pt->x * 20) + 50;
		pt->y = (pt->y * 20) + 50;
		i++;
	}
}
