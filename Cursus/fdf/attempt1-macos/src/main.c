/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:12:46 by swillis           #+#    #+#             */
/*   Updated: 2022/03/09 23:58:04 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	free(vars);
	return (1);
}

t_vars	*init_vars(void)
{
	t_vars	*vars;
	t_data	*data;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (0);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (0);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "FDF Viewer");
	if (!vars->win)
		return (0);
	vars->data = malloc(sizeof(t_data));
	if (!vars->data)
		return (0);
	data = vars->data;
	data->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (0);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
									&data->line_length, &data->endian);
	if (!data->addr)
		return (0);
	return (vars);
}

int	main(int ac, char **av)
{
	t_vars	*vars;
	t_data	*data;
	t_map	*map;

	if (ac == 2)
	{
		vars = init_vars();
		if (!vars)
			return (free_vars(vars));
		data = vars->data;
		data->map = build_map(av[1]);
		if (!data->map)
			return (free_vars(vars));
		map = data->map;

		fit_points_full_window(map, map->arr);
		// trace_map_lines(data, map, map->arr);
		trace_map_points(data, map, map->arr);
		mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);

		mlx_key_hook(vars->win, key_manager, vars);
		mlx_hook(vars->win, ON_DESTROY, 0, destroy_win, vars);
		mlx_loop(vars->mlx);
		free_vars(vars);
	}
	return (0);
}
