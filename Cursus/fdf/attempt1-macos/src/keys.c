/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:12:46 by swillis           #+#    #+#             */
/*   Updated: 2022/03/08 17:59:04 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_right(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	map->plane->a += 1;
	set_map_plane(map, map->plane->a, map->plane->b, map->plane->c);
	next_image(vars);
	fit_points_full_window(map, map->arr);
	trace_map_lines(data, map, map->arr);
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
	return (0);
}
