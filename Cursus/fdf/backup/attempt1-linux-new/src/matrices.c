/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/03/30 17:50:44 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat	*free_matrix(t_mat *mat, int rows)
{
	int		i;
	double	*row;

	i = 0;
	while (i < rows)
	{
		row = mat->tbl[i];
		free(row);
		i++;
	}
	free(mat->tbl);
	free(mat);
	return (NULL);
}

t_mat	*init_matrix(int r, int c)
{
	t_mat	*mat;
	double	*row;
	int		i;

	i = 0;
	mat = malloc(sizeof(t_mat));
	if (!mat)
		return (NULL);
	mat->r = r;
	mat->c = c;
	mat->tbl = malloc(sizeof(double *) * r);
	if (!mat->tbl)
		return (free_matrix(mat, i));
	while (i < r)
	{
		row = malloc(sizeof(double) * c);
		if (!row)
			return (free_matrix(mat, i));
		mat->tbl[i] = row;
		i++;
	}
	return (mat);
}

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
