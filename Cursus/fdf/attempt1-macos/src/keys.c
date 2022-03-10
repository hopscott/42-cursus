/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:12:46 by swillis           #+#    #+#             */
/*   Updated: 2022/03/10 21:17:20 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_right(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	basic_rotate(map, map->alpha, map->beta, map->theta + 10.0);
	basic_translate(map, map->dx, map->dy);
	next_image(vars);
	// trace_map_lines(data, map, map->arr);
	trace_map_points(data, map, map->arr);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}

void	rotate_left(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	basic_rotate(map, map->alpha, map->beta, map->theta - 10.0);
	basic_translate(map, map->dx, map->dy);
	next_image(vars);
	// trace_map_lines(data, map, map->arr);
	trace_map_points(data, map, map->arr);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}

void	translate_up(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	map->dy -= 10;
	basic_translate(map, 0.0, -10.0);
	next_image(vars);
	// trace_map_lines(data, map, map->arr);
	trace_map_points(data, map, map->arr);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}

void	translate_down(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	map->dy += 10;
	basic_translate(map, 0.0, 10.0);
	next_image(vars);
	// trace_map_lines(data, map, map->arr);
	trace_map_points(data, map, map->arr);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}

void	translate_right(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	map->dx += 10;
	basic_translate(map, 10.0, 0.0);
	next_image(vars);
	// trace_map_lines(data, map, map->arr);
	trace_map_points(data, map, map->arr);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}

void	translate_left(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	map->dx -= 10;
	basic_translate(map, -10.0, 0.0);
	next_image(vars);
	// trace_map_lines(data, map, map->arr);
	trace_map_points(data, map, map->arr);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}

int	destroy_win(t_vars *vars)
{
	free_vars(vars);
	exit(0);
	return (0);
}

int	key_manager(int keycode, t_vars *vars)
{
	ft_printf(">> KEY PRESSED >> %d\n", keycode);
	if (keycode == 53)
		destroy_win(vars);
	else if (keycode == 2)
		rotate_right(vars);
	else if (keycode == 0)
		rotate_left(vars);
	else if (keycode == 126)
		translate_up(vars);
	else if (keycode == 125)
		translate_down(vars);
	else if (keycode == 124)
		translate_right(vars);
	else if (keycode == 123)
		translate_left(vars);
	return (0);
}
