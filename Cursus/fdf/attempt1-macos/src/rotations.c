/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/03/10 00:28:32 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat	*init_matrix(int r, int c)
{
	t_mat	*mat;
	double	*row;
	int		i;

	mat = malloc(sizeof(t_mat));
	if (!mat)
		return (NULL);
	mat->r = r;
	mat->c = c;
	mat->tbl = malloc(sizeof(double *) * r);
	if (!mat->tbl)
		return (NULL);
	i = 0;
	while (i < r)
	{
		row = malloc(sizeof(double) * c);
		if (!row)
			return (NULL);
		mat->tbl[i] = row;
		i++;
	}
	return (mat);
}

#include <stdio.h>

void	set_matrix(double arr[], t_mat *mat)
{
	double	*row;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (i < mat->r)
	{
		row = mat->tbl[i];
		j = 0;
		while (j < mat->c)
		{
			row[j] = arr[k];
			j++;
			k++;
		}
		i++;
	}
}

void	print_matrix(t_mat *mat)
{
	double	*row;
	int		i;
	int		j;

	printf("===========================================\n");
	i = 0;
	while (i < mat->r)
	{
		row = mat->tbl[i];
		j = 0;
		printf("|");
		while (j < mat->c)
		{
			printf("%f", row[j]);
			if (j + 1 < mat->c)
				printf("\t");
			j++;
		}
		printf("|\n");
		i++;
	}
	printf("===========================================\n");
}

void	matrix_multipy(t_mat *m1, t_mat *m2, t_mat *res)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < m1->r)
	{
		j = 0;
		while (j < m2->c)
		{
			res->tbl[i][j] = 0;
			k = 0;
			while (k < m2->r)
			{
				res->tbl[i][j] += m1->tbl[i][k] * m2->tbl[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
}

void	set_rotation_x(t_map *map, double theta)
{
	double	arr[9];

	printf(">>%f\n", theta);
	arr[0] = 1.0;
	arr[1] = 0.0;
	arr[2] = 0.0;
	arr[3] = 0.0;
	arr[4] = cos(deg2rad(theta));
	arr[5] = -sin(deg2rad(theta));
	arr[6] = 0.0;
	arr[7] = sin(deg2rad(theta));
	arr[8] = cos(deg2rad(theta));
	int i = -1;
	while (i++ < 8)
		printf(">%d> %f\n", i, arr[i]);
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

// https://en.wikipedia.org/wiki/Isometric_projection
// https://en.wikipedia.org/wiki/Rotation_matrix#:~:text=A%20basic%20rotation%20(also%20called,which%20codifies%20their%20alternating%20signs.
void	basic_rotate(t_map *map, double alpha, double beta, double theta)
{
	map->alpha += alpha;
	map->beta += beta;
	map->theta += theta;
	set_rotation_x(map, map->alpha);
	set_rotation_y(map, map->beta);
	set_rotation_z(map, map->theta);
	print_matrix(map->rx);
	print_matrix(map->ry);
	print_matrix(map->rz);
	/////////////////////////////////
	t_mat	*tmp;

	tmp = init_matrix(3, 3);
	matrix_multipy(map->rx, map->ry, tmp);
	matrix_multipy(tmp, map->rz, map->r);
	print_matrix(map->r);
	/////////////////////////////////
	double		arr[3];
	t_mat	*xyz;
	t_mat	*res;
	int		i;
	t_point	*pt;

	xyz = init_matrix(3, 1);
	res = init_matrix(3, 1);
	i = 0;
	while (i < map->points)
	{
		pt = map->arr[i];
		arr[0] = (double)pt->x;
		arr[1] = (double)pt->y;
		arr[2] = (double)pt->z;
		set_matrix(arr, xyz);
		matrix_multipy(map->r, xyz, res);
		pt->px = res->tbl[0][0];
		pt->py = res->tbl[1][0];
		i++;
	}
}
