/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/03/22 23:52:29 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	recenter_xyz(t_map *map, t_point **arr)
{
	int		i;
	t_point	*pt;

	i = 0;
	while (i < map->points)
	{
		pt = arr[i];
		pt->x -= map->cols / 2;
		pt->y -= map->rows / 2;
		i++;
	}
}

void	uncenter_xyz(t_map *map, t_point **arr)
{
	int		i;
	t_point	*pt;

	i = 0;
	while (i < map->points)
	{
		pt = arr[i];
		pt->x += map->cols / 2;
		pt->y += map->rows / 2;
		i++;
	}
}

void	basic_translate(t_map *map, double dx, double dy)
{
	int		i;
	t_point	*pt;

	i = 0;
	while (i < map->points)
	{
		pt = map->arr[i];
		pt->px += dx;
		pt->py += dy;
		i++;
	}
}

void	basic_zoom(t_map *map, int zoom)
{
	int		i;
	t_point	*pt;

	recenter_xyz(map, map->arr);
	i = 0;
	while (i < map->points)
	{
		pt = map->arr[i];
		pt->x = (pt->x / map->zoom) * zoom;
		pt->y = (pt->y / map->zoom) * zoom;
		pt->z = (pt->z / map->zoom) * zoom;
		i++;
	}
	map->zoom = zoom;
	uncenter_xyz(map, map->arr);
	find_map_heights(map, map->arr);
}
