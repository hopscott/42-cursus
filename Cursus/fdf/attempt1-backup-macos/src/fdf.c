/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:12:46 by swillis           #+#    #+#             */
/*   Updated: 2022/03/02 00:27:47 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int destroy_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit(0);
	return (0);
}

int close_win(int keycode, t_vars *vars)
{
	if (keycode == 53)
	//if (keycode == 65307)
		destroy_win(vars);
	return (0);
}

int main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;
	t_map	map;

	if (ac == 2)
	{
		// file
		map = build_map(av[1]);

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
		vars.data = &img;
		img.map = &map;
		img.img = mlx_new_image(vars.mlx, HEIGHT, WIDTH);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
									 &img.line_length, &img.endian);

//		space_map_points(&map, map.arr);
//		isometric_map_points(&map, map.arr_pt);

		fit_points_full_window(&map, map.arr);

		trace_map_lines(&img, img.map);
		trace_map_points(&img, img.map);

		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

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
