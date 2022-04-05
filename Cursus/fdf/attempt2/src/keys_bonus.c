/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:12:46 by swillis           #+#    #+#             */
/*   Updated: 2022/04/05 14:52:47 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	toggle_render(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	if (map->type > 1)
		map->type = 0;
	else
		map->type += 1;
	next_image(vars);
	render_map(data, map);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}

void	zoom_in(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	if (map->zoom < 20)
	{
		basic_zoom(map, map->zoom + 2);
		basic_rotate(map, map->alpha, map->beta, map->theta);
		basic_translate(map, map->dx, map->dy);
		next_image(vars);
		render_map(data, map);
		mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
	}
}

void	zoom_out(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	if (map->zoom > 2)
	{
		basic_zoom(map, map->zoom - 2);
		basic_rotate(map, map->alpha, map->beta, map->theta);
		basic_translate(map, map->dx, map->dy);
		next_image(vars);
		render_map(data, map);
		mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
	}
}

void	isometric_view(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	basic_zoom(map, 1);
	basic_rotate(map, 45.0, asin(tan(deg2rad(30))), 45.0);
	map->dx = 0.0;
	map->dy = 0.0;
	basic_translate(map, map->dx, map->dy);
	fit_points_full_window(map, map->arr);
	next_image(vars);
	render_map(data, map);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}

void	parallel_view(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	basic_zoom(map, 1);
	basic_rotate(map, 0.0, 0.0, 0.0);
	map->dx = 0.0;
	map->dy = 0.0;
	basic_translate(map, map->dx, map->dy);
	fit_points_full_window(map, map->arr);
	next_image(vars);
	render_map(data, map);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}
