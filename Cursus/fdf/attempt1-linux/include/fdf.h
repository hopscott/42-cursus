/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:31:50 by swillis           #+#    #+#             */
/*   Updated: 2022/02/22 18:01:54 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <fcntl.h>
#include "libft.h"
#include "ft_printf.h"
#include <mlx.h>

# define HEIGHT 800
# define WIDTH 600

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	*data;
	t_data	*data_l;
	t_data	*data_r;
}				t_vars;

#endif
