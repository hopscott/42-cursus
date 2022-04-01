/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:12:46 by swillis           #+#    #+#             */
/*   Updated: 2022/03/07 01:15:37 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	next_image(t_vars *vars)
{
	t_data	*data;
	t_map	*map;

	data = vars->data;
	map = data->map;
	mlx_destroy_image(vars->mlx, data->img);
	data->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!data->img)
		destroy_win(vars);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
									&data->line_length, &data->endian);
	if (!data->addr)
		destroy_win(vars);
}
