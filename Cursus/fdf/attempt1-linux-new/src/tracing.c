/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:12:46 by swillis           #+#    #+#             */
/*   Updated: 2022/03/22 23:38:10 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	next_image(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	mlx_destroy_image(vars->mlx, data->img);
	data->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!data->img)
		destroy_win(vars);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
									&data->line_length, &data->endian);
	if (!data->addr)
		destroy_win(vars);
}

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
		my_mlx_pixel_put(data, (int)pt->px, (int)pt->py, rgb_colour(255, 255, 255));
		i++;
	}
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
		if ((i + 1) % map->cols != 0)
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

void	trace_map_gradients(t_data *data, t_map *map, t_point **arr)
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
		if ((i + 1) % map->cols != 0)
			bresenham_trace_gradient(data, p1, p2);
		i++;
	}
	i = 0;
	while (i + map->cols < map->points)
	{
		p1 = arr[i];
		p3 = arr[i + map->cols];
		bresenham_trace_gradient(data, p1, p3);
		i++;
	}
}