/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:11 by swillis           #+#    #+#             */
/*   Updated: 2022/02/24 23:06:43 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	trace_map_points(t_data *img, t_map *map)
{
	int		i;
	t_point	*pt;

	i = 0;
	while (i < map->points)
	{
		pt = map->arr_pt[i];
		if (pt->z == 0)
			my_mlx_pixel_put(img, pt->x, pt->y, 0xFFFFFF);
		else
			my_mlx_pixel_put(img, pt->x, pt->y, 0x0000FF);
		i++;
	}
}

void	bresenham_trace(t_data *img, t_point *p1, t_point *p2)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;

	dx = p2->x - p1->x;
	dy = p2->y - p1->y;

	// https://personal.math.ubc.ca/~cass/courses/m308-02b/projects/puhalovic/#alldirections
	// https://stackoverflow.com/questions/62651042/how-to-implement-bresenhams-line-algorithm-in-c-when-trying-to-draw-a-line-in-b
	if ((0 < (dy / dx)) && ((dy / dx)) < 1))
	{
		x = p1->x;
		y = p1->y;
		p = 2 * dy - dx;
		while (x <= p2->x)
		{
			my_mlx_pixel_put(img, x, y, 0xFF0000);
			if (p >= 0)
			{
				y += 1;
				p = p + (2 * dy) - (2 * dx);
			}
			else
				p = p + (2 * dy);
			x += 1;
		}
	}
}

void	trace_map_lines(t_data *img, t_map *map)
{
	int		i;
	t_point	*p1;
	t_point	*p2;

	i = 0;
	while (i + 1 < map->points)
	{
		p1 = map->arr_pt[i];
		p2 = map->arr_pt[i + 1];
		bresenham_trace(img, p1, p2);
		i++;
	}
}