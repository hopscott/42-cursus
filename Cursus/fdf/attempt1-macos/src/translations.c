/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/03/10 20:09:00 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

// https://en.wikipedia.org/wiki/Isometric_projection
// https://en.wikipedia.org/wiki/Rotation_matrix#:~:text=A%20basic%20rotation%20(also%20called,which%20codifies%20their%20alternating%20signs.
// ============================================================
// https://medium.com/swlh/understanding-3d-matrix-transforms-with-pixijs-c76da3f8bd8

void	basic_zoom(t_map *map, int zoom)
{
	(void)map;
	(void)zoom;
}
