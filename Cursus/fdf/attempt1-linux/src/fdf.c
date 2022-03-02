/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:12:46 by swillis           #+#    #+#             */
/*   Updated: 2022/03/02 19:41:30 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_fdf(t_vars *vars)
{
	t_data	*data;
	t_map	*map;
	t_point	**arr;
	t_point	*pt;
	int		i;

	data = vars->data;
	map = data->map;
	arr = map->arr;
	// free
	ft_printf("FREE >> data->img");
	free(data->img);
	ft_printf(" >> SUCCESS\n");
	ft_printf("FREE >> map->plane");
	free(map->plane);
	ft_printf(" >> SUCCESS\n");
	i = 0;
	while (i < map->points)
	{
		pt = arr[i];
		ft_printf("FREE >> pt");
		free(pt);
		ft_printf(" >> SUCCESS\n");
		i++;
	}
	ft_printf("FREE >> arr");
	free(arr);
	ft_printf(" >> SUCCESS\n");
	ft_printf("FREE >> map");
	free(map);
	ft_printf(" >> SUCCESS\n");
	//ft_printf("FREE >> vars");
	//free(vars);
	//ft_printf(" >> SUCCESS\n");
}

int destroy_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_fdf(vars);
	exit(0);
	return (0);
}

int close_win(int keycode, t_vars *vars)
{
	//if (keycode == 53)
	if (keycode == 65307)
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
		// init
		vars.mlx = mlx_init();
		if (vars.mlx == NULL)
			return (1);
		vars.win = mlx_new_window(vars.mlx, HEIGHT, WIDTH, "FDF Viewer");
		if (vars.win == NULL)
		{
			free(vars.win);
			return (1);
		}

		data = vars.data;
		data = malloc(sizeof(t_data));
		if (!data)
			return (1);
		
		map = data->map;
		map = malloc(sizeof(t_map));
		if (!map)
			return (1);
		map = build_map(av[1]);
		data->img = mlx_new_image(vars.mlx, HEIGHT, WIDTH);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
									 &data->line_length, &data->endian);

		fit_points_full_window(map, map->arr);
		trace_map_points(data, data->map);

//		trace_map_lines(data, data->map);

		mlx_put_image_to_window(vars.mlx, vars.win, data->img, 0, 0);

		// update img
		// mlx_loop_hook(vars.mlx, render_next_frame, &vars);

		// esc keys
		mlx_key_hook(vars.win, close_win, &vars);
		mlx_hook(vars.win, ON_DESTROY, 0, destroy_win, &vars);

		// loop
		mlx_loop(vars.mlx);
	}
	return (0);
}
