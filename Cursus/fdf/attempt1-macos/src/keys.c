/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:12:46 by swillis           #+#    #+#             */
/*   Updated: 2022/03/23 13:00:42 by swillis          ###   ########.fr       */
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
	basic_zoom(map, map->zoom + 1);
	basic_rotate(map, map->alpha, map->beta, map->theta);
	basic_translate(map, map->dx, map->dy);
	next_image(vars);
	render_map(data, map);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}

void	zoom_out(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	if (map->zoom > 2)
	{
		basic_zoom(map, map->zoom - 1);
		basic_rotate(map, map->alpha, map->beta, map->theta);
		basic_translate(map, map->dx, map->dy);
		next_image(vars);
		render_map(data, map);
		mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
	}
}

void	rotate_up(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	basic_zoom(map, map->zoom);
	basic_rotate(map, map->alpha - 15.0, map->beta, map->theta);
	basic_translate(map, map->dx, map->dy);
	next_image(vars);
	render_map(data, map);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}

void	rotate_down(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	basic_zoom(map, map->zoom);
	basic_rotate(map, map->alpha + 15.0, map->beta, map->theta);
	basic_translate(map, map->dx, map->dy);
	next_image(vars);
	render_map(data, map);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}

void	rotate_right(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	basic_zoom(map, map->zoom);
	basic_rotate(map, map->alpha, map->beta, map->theta + 15.0);
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
	basic_rotate(map, map->alpha, map->beta, map->theta - 15.0);
	basic_translate(map, map->dx, map->dy);
	next_image(vars);
	render_map(data, map);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}

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

int	destroy_win(t_vars *vars)
{
	free_vars(vars);
	exit(0);
	return (0);
}

int	key_manager(int keycode, t_vars *vars)
{
	// ft_printf(">> KEY PRESSED >> %d\n", keycode);
	if (keycode == 53)
		destroy_win(vars);
	else if (keycode == 13)
		rotate_up(vars);
	else if (keycode == 1)
		rotate_down(vars);
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
	else if (keycode == 14)
		zoom_in(vars);
	else if (keycode == 12)
		zoom_out(vars);
	else if (keycode == 17)
		toggle_render(vars);
	return (0);
}
