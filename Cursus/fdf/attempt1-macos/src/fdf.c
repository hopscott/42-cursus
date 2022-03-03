/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:12:46 by swillis           #+#    #+#             */
/*   Updated: 2022/03/03 23:08:19 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	free_arr_points(t_point **arr, int len)
{
	t_point	*pt;
	int		i;

	i = 0;
	while (i < len)
	{
		pt = arr[i];
		free(pt);
		i++;
	}
	free(arr);
}

void	free_map(t_map *map)
{
	if (map->arr)
		free_arr_points(map->arr, map->points);
	if (map->plane)
		free(map->plane);
	free(map);
}

int	free_vars(t_vars *vars)
{
	if (vars->mlx)
	{
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		else		
			free(vars->mlx);
	}
	if (vars->data)
	{
		if (vars->data->img)
			free(vars->data->img);
		if (vars->data->addr)
			free(vars->data->addr);
		if (vars->data->map)
			free_map(vars->data->map);
		free(vars->data);
	}
	return (1);
}

int destroy_win(t_vars *vars)
{
	free_vars(vars);
	exit(0);
	return (0);
}

void	next_image(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	mlx_destroy_image(vars->mlx, data->img);
	data->img = mlx_new_image(vars->mlx, HEIGHT, WIDTH);
	if (!data->img)
		destroy_win(vars);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
									&data->line_length, &data->endian);
	if (!data->addr)
		destroy_win(vars);
}

int	zoom_in(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	map->plane->a += 1;
	map->plane->b += 1;
	set_map_plane(map, map->plane->a, map->plane->b, map->plane->c);
	next_image(vars);
	trace_map_lines(data, map, map->arr);
	trace_map_points(data, map, map->arr);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img,  0, 0);
	return (0);
}

int	isometric_full(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	reset_points(map, map->arr);
	set_map_plane(map, 1, 1, 1);
	next_image(vars);
	fit_points_full_window(map, map->arr);
	trace_map_lines(data, map, map->arr);
	trace_map_points(data, map, map->arr);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img,  0, 0);
	return (0);
}

int	translate_left(t_vars *vars)
{
	t_data	*data;
	t_map	*map;
	t_point	*pt;
	int		i;

	data = vars->data;
	map = data->map;
	i = 0;
	while (i < map->points)
	{
		pt = map->arr[i];
		pt->u -= 10;
		i++;
	}
	next_image(vars);
	trace_map_lines(data, map, map->arr);
	trace_map_points(data, map, map->arr);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img,  0, 0);
	return (0);
}

int	translate_right(t_vars *vars)
{
	t_data	*data;
	t_map	*map;
	t_point	*pt;
	int		i;

	data = vars->data;
	map = data->map;
	i = 0;
	while (i < map->points)
	{
		pt = map->arr[i];
		pt->u += 10;
		i++;
	}
	next_image(vars);
	trace_map_lines(data, map, map->arr);
	trace_map_points(data, map, map->arr);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img,  0, 0);
	return (0);
}

int	translate_up(t_vars *vars)
{
	t_data	*data;
	t_map	*map;
	t_point	*pt;
	int		i;

	data = vars->data;
	map = data->map;
	i = 0;
	while (i < map->points)
	{
		pt = map->arr[i];
		pt->v -= 10;
		i++;
	}
	next_image(vars);
	trace_map_lines(data, map, map->arr);
	trace_map_points(data, map, map->arr);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img,  0, 0);
	return (0);
}

int	translate_down(t_vars *vars)
{
	t_data	*data;
	t_map	*map;
	t_point	*pt;
	int		i;

	data = vars->data;
	map = data->map;
	i = 0;
	while (i < map->points)
	{
		pt = map->arr[i];
		pt->v += 10;
		i++;
	}
	next_image(vars);
	trace_map_lines(data, map, map->arr);
	trace_map_points(data, map, map->arr);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img,  0, 0);
	return (0);
}

int key_manager(int keycode, t_vars *vars)
{
	ft_printf(">> KEY PRESSED >> %d\n", keycode);
	if (keycode == 53) // esc - 53 / linux - 65307
		destroy_win(vars);
	else if (keycode == 34) // i - 34
		isometric_full(vars);
	else if (keycode == 14) // e - 14
		zoom_in(vars);
	else if (keycode == 123) // left - 123
		translate_left(vars);
	else if (keycode == 124) // right - 124
		translate_right(vars);
	else if (keycode == 125) // down - 125
		translate_down(vars);
	else if (keycode == 126) // up - 126
		translate_up(vars);
	return (0);
}

int main(int ac, char **av)
{
	t_vars	vars;
	t_data	*data;
	t_map	*map;

	if (ac == 2)
	{
		// mlx
		vars.mlx = mlx_init();
		if (!vars.mlx)
			return (1);
		// win
		vars.win = mlx_new_window(vars.mlx, HEIGHT, WIDTH, "FDF Viewer");
		if (!vars.win)
			free_vars(&vars);
		// data
		vars.data = malloc(sizeof(t_data));
		if (!vars.data)
			free_vars(&vars);
		// img
		data = vars.data;
		data->img = mlx_new_image(vars.mlx, HEIGHT, WIDTH);
		if (!data->img)
			free_vars(&vars);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
									 &data->line_length, &data->endian);
		if (!data->addr)
			free_vars(&vars);
		// map
		data->map = build_map(av[1]);
		if (!data->map)
			free_vars(&vars);

		map = data->map;
//		fit_points_full_window(map, map->arr);
		trace_map_lines(data, map, map->arr);
		trace_map_points(data, map, map->arr);
		mlx_put_image_to_window(vars.mlx, vars.win, data->img, 0, 0);

		mlx_key_hook(vars.win, key_manager, &vars);
		mlx_hook(vars.win, ON_DESTROY, 0, destroy_win, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
