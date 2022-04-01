/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_translate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:12:46 by swillis           #+#    #+#             */
/*   Updated: 2022/04/01 17:39:23 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_up(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	map->dy -= 25;
	basic_translate(map, 0.0, -25.0);
	next_image(vars);
	render_map(data, map);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}

void	translate_down(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	map->dy += 25;
	basic_translate(map, 0.0, 25.0);
	next_image(vars);
	render_map(data, map);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}

void	translate_right(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	map->dx += 25;
	basic_translate(map, 25.0, 0.0);
	next_image(vars);
	render_map(data, map);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}

void	translate_left(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	map->dx -= 25;
	basic_translate(map, -25.0, 0.0);
	next_image(vars);
	render_map(data, map);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}
