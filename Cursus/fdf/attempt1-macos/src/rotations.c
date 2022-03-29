/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/03/22 18:22:26 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_rotation_x(t_map *map, double theta)
{
	double	arr[9];

	arr[0] = 1.0;
	arr[1] = 0.0;
	arr[2] = 0.0;
	arr[3] = 0.0;
	arr[4] = cos(deg2rad(theta));
	arr[5] = -sin(deg2rad(theta));
	arr[6] = 0.0;
	arr[7] = sin(deg2rad(theta));
	arr[8] = cos(deg2rad(theta));
	set_matrix(arr, map->rx);
}

void	set_rotation_y(t_map *map, double theta)
{
	double	arr[9];

	arr[0] = cos(deg2rad(theta));
	arr[1] = 0.0;
	arr[2] = sin(deg2rad(theta));
	arr[3] = 0.0;
	arr[4] = 1.0;
	arr[5] = 0.0;
	arr[6] = -sin(deg2rad(theta));
	arr[7] = 0.0;
	arr[8] = cos(deg2rad(theta));
	set_matrix(arr, map->ry);
}

void	set_rotation_z(t_map *map, double theta)
{
	double	arr[9];

	arr[0] = cos(deg2rad(theta));
	arr[1] = -sin(deg2rad(theta));
	arr[2] = 0.0;
	arr[3] = sin(deg2rad(theta));
	arr[4] = cos(deg2rad(theta));
	arr[5] = 0.0;
	arr[6] = 0.0;
	arr[7] = 0.0;
	arr[8] = 1.0;
	set_matrix(arr, map->rz);
}

void	rotate_points(t_map *map)
{
	int		i;
	t_point	*pt;
	double	arr[3];
	t_mat	*xyz;
	t_mat	*tmp;

	xyz = init_matrix(3, 1);
	tmp = init_matrix(3, 1);
	if (!xyz || !tmp)
		return ;
	i = 0;
	while (i < map->points)
	{
		pt = map->arr[i];
		arr[0] = (double)pt->x;
		arr[1] = (double)pt->y;
		arr[2] = (double)pt->z;
		set_matrix(arr, xyz);
		matrix_multipy(map->r, xyz, tmp);
		pt->px = tmp->tbl[0][0];
		pt->py = tmp->tbl[1][0];
		i++;
	}
	free_matrix(xyz, xyz->r);
	free_matrix(tmp, tmp->r);
}

void	basic_rotate(t_map *map, double alpha, double beta, double theta)
{
	t_mat	*tmp;

	map->alpha = alpha;
	map->beta = beta;
	map->theta = theta;
	set_rotation_x(map, map->alpha);
	set_rotation_y(map, map->beta);
	set_rotation_z(map, map->theta);
	tmp = init_matrix(3, 3);
	matrix_multipy(map->rx, map->ry, tmp);
	matrix_multipy(tmp, map->rz, map->r);
	free_matrix(tmp, tmp->r);
	recenter_xyz(map, map->arr);
	rotate_points(map);
	uncenter_xyz(map, map->arr);
	find_map_heights(map, map->arr);
}
