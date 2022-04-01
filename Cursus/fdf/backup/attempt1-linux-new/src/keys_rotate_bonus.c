/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:12:46 by swillis           #+#    #+#             */
/*   Updated: 2022/04/01 19:04:44 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_up(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	if (fabs(map->alpha - 7.5) <= 90)
	{
		basic_zoom(map, map->zoom);
		basic_rotate(map, map->alpha - 7.5, map->beta, map->theta);
		basic_translate(map, map->dx, map->dy);
		next_image(vars);
		render_map(data, map);
		mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
	}
}

void	rotate_down(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	if (fabs(map->alpha + 7.5) <= 90)
	{
		basic_zoom(map, map->zoom);
		basic_rotate(map, map->alpha + 7.5, map->beta, map->theta);
		basic_translate(map, map->dx, map->dy);
		next_image(vars);
		render_map(data, map);
		mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
	}
}

void	rotate_right(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	basic_zoom(map, map->zoom);
	basic_rotate(map, map->alpha, map->beta, map->theta + 7.5);
	basic_translate(map, map->dx, map->dy);
	next_image(vars);
	render_map(data, map);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}

void	rotate_left(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	basic_zoom(map, map->zoom);
	basic_rotate(map, map->alpha, map->beta, map->theta - 7.5);
	basic_translate(map, map->dx, map->dy);
	next_image(vars);
	render_map(data, map);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}
