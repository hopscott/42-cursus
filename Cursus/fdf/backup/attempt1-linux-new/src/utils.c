/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:12:46 by swillis           #+#    #+#             */
/*   Updated: 2022/04/01 19:04:29 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	destroy_win(t_vars *vars)
{
	free_vars(vars);
	exit(0);
	return (0);
}

int	key_manager(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		destroy_win(vars);
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
