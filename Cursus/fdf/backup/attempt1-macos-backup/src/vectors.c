/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:25 by swillis           #+#    #+#             */
/*   Updated: 2022/03/08 17:52:47 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	normalise_arr_int(int arr[], int len)
{
	int	i;
	int	max;

	i = 0;
	max = arr[i];
	while (i < len)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		arr[i] /= max;
		i++;
	}
}

int	vector_dot(int a[], int b[], int len)
{
	int	dot;
	int	i;

	i = 0;
	dot = 0;
	while (i < len)
	{
		dot += a[i] * b[i];
		i++;
	}
	return (dot);
}

void	vector_cross(int a[], int b[], int dst[])
{
	int	cross[3];

	cross[0] = a[1] * b[2] - a[2] * b[1];
	cross[1] = a[2] * b[0] - a[0] * b[2];
	cross[2] = a[0] * b[1] - a[1] * b[0];
	dst[0] = cross[0];
	dst[1] = cross[1];
	dst[2] = cross[2];
}

void	vector_multiply(int a, int b[], int dst[])
{
	dst[0] = a * b[0];
	dst[1] = a * b[1];
	dst[2] = a * b[2];
}

void	vector_add(int a[], int b[], int dst[])
{
	dst[0] = a[0] + b[0];
	dst[1] = a[1] + b[1];
	dst[2] = a[2] + b[2];
}
