/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:12:46 by swillis           #+#    #+#             */
/*   Updated: 2022/04/01 18:15:02 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	destroy_win(t_vars *vars)
{
	free_vars(vars);
	exit(0);
	return (0);
}

void	view_key_manager(int keycode, t_vars *vars)
{
	if (keycode == 116)
		toggle_render(vars);
	else if (keycode == 105)
		isometric_view(vars);
	else if (keycode == 112)
		parallel_view(vars);
}

int	key_manager(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		destroy_win(vars);
	else if (keycode == 119)
		rotate_up(vars);
	else if (keycode == 115)
		rotate_down(vars);
	else if (keycode == 100)
		rotate_right(vars);
	else if (keycode == 97)
		rotate_left(vars);
	else if (keycode == 65362)
		translate_up(vars);
	else if (keycode == 65364)
		translate_down(vars);
	else if (keycode == 65363)
		translate_right(vars);
	else if (keycode == 65361)
		translate_left(vars);
	else if (keycode == 101)
		zoom_in(vars);
	else if (keycode == 113)
		zoom_out(vars);
	else if ((keycode == 116) || (keycode == 105) || (keycode == 112))
		view_key_manager(keycode, vars);
	return (0);
}

int	check_fdf(char *str)
{
	int	i;
	int	fd;

	i = ft_strlen((unsigned char *)str);
	i -= 1;
	if ((str[i - 3] == '.') && (str[i - 2] == 'f') && \
					(str[i - 1] == 'd') && (str[i] == 'f'))
	{
		fd = open(str, O_RDONLY);
		if (!fd)
		{
			ft_printf("File read ERROR - Cannot open '.fdf' file !\n");
			return (0);
		}
		close(fd);
		return (1);
	}
	else
	{
		ft_printf("File path ERROR - no '.fdf' file extension found !\n");
		return (0);
	}
}
