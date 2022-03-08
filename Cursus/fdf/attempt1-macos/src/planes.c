/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/03/08 17:54:56 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// https://en.wikipedia.org/wiki/3D_projection#:~:text=A%203D%20projection%20(or%20graphical,capability%20on%20a%20simpler%20plane.
void	plane_mapping(t_map *map, t_plane *plane, t_point **arr)
{
	t_point	*pt;
	int		xyz[3];
	int		i;

	i = 0;
	while (i < map->points)
	{
		pt = arr[i];
		xyz[0] = pt->x;
		xyz[1] = pt->y;
		xyz[2] = pt->z;
		pt->px = vector_dot(plane->u, xyz, 3);
		pt->py = vector_dot(plane->v, xyz, 3);
		i++;
	}
}

// https://stackoverflow.com/questions/18663755/how-to-convert-a-3d-point-on-a-plane-to-uv-coordinates
void	set_map_plane(t_map *map, int a, int b, int c)
{
	map->plane->a = a;
	map->plane->b = b;
	map->plane->c = c;
	map->plane->n[0] = map->plane->a;
	map->plane->n[1] = map->plane->b;
	map->plane->n[2] = map->plane->c;
	map->plane->u[0] = map->plane->n[1];
	map->plane->u[1] = -1 * map->plane->n[0];
	map->plane->u[2] = 0;
	if ((map->plane->n[0] == 0) && (map->plane->n[1] == 0))
	{
		map->plane->u[0] = 0;
		map->plane->u[1] = 0;
		map->plane->u[2] = map->plane->n[2];
	}
	normalise_arr_int(map->plane->u, 3);
	vector_cross(map->plane->n, map->plane->u, map->plane->v);
	plane_mapping(map, map->plane, map->arr);
}
