/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:54:11 by swillis           #+#    #+#             */
/*   Updated: 2022/03/08 17:52:34 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int px, int py, int color)
{
	char	*dst;

	if (((0 <= px) && (px < WIDTH)) && ((0 <= py) && (py < HEIGHT)))
	{
		dst = data->addr + (py * data->line_length + \
								px * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	trace_map_points(t_data *data, t_map *map, t_point **arr)
{
	int		i;
	t_point	*pt;

	i = 0;
	while (i < map->points)
	{
		pt = arr[i];
		if (pt->height == 0)
			my_mlx_pixel_put(data, pt->px, pt->py, 0xFFFFFF);
		else
			my_mlx_pixel_put(data, pt->px, pt->py, 0x0000FF);
		i++;
	}
}

/*

void	bresenham_plot(t_data *data, t_pixel start, t_pixel end)
{
	int	dx;
	int	dy;
	int	d;
	int	inc_e;
	int	inc_ne;

	dx = end.x - start.x;
	dy = end.y - start.y;
	inc_e = 2 * dy;
	inc_ne = 2 * dy - 2 * dx;
	d = 2 * dy - dx;
	while (start.x <= end.x)
	{
		my_mlx_pixel_put(data, start.x, start.y, 0xFF0000);
		if (d <= 0)
			d += inc_e;
		else
		{
			d += inc_ne;
			start.y += 1;
			if (dy < 0)
				start.y += -1;
		}
		start.x += 1;
	}
}

//https://webcache.googleusercontent.com/search?q=cache:MTVvqc2k2ssJ:https://www.geeksforgeeks.org/illustration-for-tracing-all-the-8-octaves-in-bresenhams-line-algorithm/+&cd=2&hl=en&ct=clnk&gl=fr
void	bresenham_trace(t_data *data, t_point *p1, t_point *p2)
{
	t_pixel	start;
	t_pixel	end;

	start.x = p1->px;
	start.y = p1->py;
	end.x = p2->px;
	end.y = p2->py;
	if ((end.x - start.x) < 0)
	{
		start.x = p2->px;
		start.y = p2->py;
		end.x = p1->px;
		end.y = p1->py;
	}
	if ((end.x - start.x) == 0)
	{
		start.x = p1->py;
		start.y = p1->px;
		end.x = p2->py;
		end.y = p2->px;
	}
	bresenham_plot(data, start, end);
}
*/


/*
void	bresenham_define_d(int w, int h, int d[])
{
	d[0] = 0;
	d[1] = 0;
	d[2] = 0;
	d[3] = 0;
	if (w < 0)
	{
		d[0] = -1;
		d[2] = -1;
	}
	else if (w > 0)
	{
		d[0] = 1;
		d[2] = 1;
	}
	if (h < 0)
		d[1] = -1;
	else if (h > 0)
		d[1] = 1;
}

void	bresenham_define_lsn(int w, int h, int lsn[], int d[])
{
	int	longest;
	int	shortest;
	int	numerator;

	longest = abs(w);
	shortest = abs(h);
	if (shortest > longest)
	{
		longest = abs(h);
		shortest = abs(w);
		if (h < 0)
			d[3] = -1;
		else if (h > 0)
			d[3] = 1;
	}
	numerator = longest >> 1;
	lsn[0] = longest;
	lsn[1] = shortest;
	lsn[2] = numerator;
}

void	bresenham_plot(t_data *data, t_point *p1, int d[], int lsn[])
{
	int	i;
	int	x;
	int	y;

	x = p1->px;
	y = p1->py;
	i = 0;
	while (i <= lsn[0])
	{
		my_mlx_pixel_put(data, x, y, 0xFF0000);
		lsn[2] += lsn[1];
		if (lsn[2] > lsn[0])
		{
			lsn[2] -= lsn[0];
			x += d[0];
			y += d[1];
		}
		else
		{
			x += d[2];
			y += d[3];
		}
		i++;
	}
}

// https://tech-algorithm.com/articles/drawing-line-using-bresenham-algorithm/
void	bresenham_trace(t_data *data, t_point *p1, t_point *p2)
{
	int	w;
	int	h;
	int	d[4];
	int	lsn[3];

	w = p2->px - p1->px;
	h = p2->py - p1->py;
	bresenham_define_d(w, h, d);
	bresenham_define_lsn(w, h, lsn, d);
	bresenham_plot(data, p1, d, lsn);
}
*/


// https://personal.math.ubc.ca/~cass/courses/m308-02b/projects/puhalovic/#alldirections
// https://stackoverflow.com/questions/62651042/how-to-implement-bresenhams-line-algorithm-in-c-when-trying-to-draw-a-line-in-b
void bresenham_trace(t_data *img, t_point *p1, t_point *p2)
{
	// https://medium.com/geekculture/bresenhams-line-drawing-algorithm-2e0e953901b3
	// case 0 = x1 < x2
	// case 1 = x1 > x2
	int sx;
	int sy;
	int dx;
	int dy;
	int err;

	dx = abs(p2->px - p1->px);
	dy = abs(p2->py - p1->py);
	sx = 1;
	if (p1->px > p2->px)
		sx = -1;
	sy = 1;
	if (p1->py > p2->py)
		sy = -1;
	err = dx / 2;
	if (dx < dy)
		err = dy / 2;

	int x = p1->px;
	int y = p1->py;
	if (dx == 0)
	{
		while (y != p2->py)
		{
			my_mlx_pixel_put(img, x, y, 0xFF0000);
			if (err > -dx)
			{
				err -= dy;
				x += sx;
			}
			if (err < dy)
			{
				err += dx;
				y += sy;
			}
		}
	}
	if (dy == 0)
	{
		while (x != p2->px)
		{
			my_mlx_pixel_put(img, x, y, 0xFF0000);
			if (err > -dx)
			{
				err -= dy;
				x += sx;
			}
			if (err < dy)
			{
				err += dx;
				y += sy;
			}
		}
	}
	else
	{
		while ((x != p2->px) && (y != p2->py))
		{
			my_mlx_pixel_put(img, x, y, 0xFF0000);
			if (err > -dx)
			{
				err -= dy;
				x += sx;
			}
			if (err < dy)
			{
				err += dx;
				y += sy;
			}
		}
	}
	my_mlx_pixel_put(img, x, y, 0xFF0000);
}

void	trace_map_lines(t_data *data, t_map *map, t_point **arr)
{
	int		i;
	t_point	*p1;
	t_point	*p2;
	t_point	*p3;

	i = 0;
	while (i + 1 < map->points)
	{
		p1 = arr[i];
		p2 = arr[i + 1];
		if (p2->col != 0)
			bresenham_trace(data, p1, p2);
		i++;
	}
	i = 0;
	while (i + map->cols < map->points)
	{
		p1 = arr[i];
		p3 = arr[i + map->cols];
		bresenham_trace(data, p1, p3);
		i++;
	}
}
