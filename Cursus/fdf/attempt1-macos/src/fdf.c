/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:12:46 by swillis           #+#    #+#             */
/*   Updated: 2022/03/03 20:11:21 by swillis          ###   ########.fr       */
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

int close_win(int keycode, t_vars *vars)
{
	if (keycode == 53) // linux - 65307
		destroy_win(vars);
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

		// tracing
		fit_points_full_window(map, map->arr);
		trace_map_points(data, map, map->arr);
		trace_map_lines(data, map, map->arr);

		// esc keys
		mlx_key_hook(vars.win, close_win, &vars);
		mlx_hook(vars.win, ON_DESTROY, 0, destroy_win, &vars);

		// loop
		mlx_put_image_to_window(vars.mlx, vars.win, data->img, 0, 0);
		mlx_loop(vars.mlx);
	}
	return (0);
}
