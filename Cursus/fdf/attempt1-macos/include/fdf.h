/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:47:18 by swillis           #+#    #+#             */
/*   Updated: 2022/03/07 01:26:02 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 600

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_point
{
	int	col;
	int	row;
	int	height;
	int	x;
	int	y;
	int	z;
	int	px;
	int	py;
}			t_point;

typedef struct s_map
{
	int		cols;
	int		rows;
	int		points;
	t_point	**arr;
	int		alpha;
	int		px_min;
	int		px_max;
	int		py_min;
	int		py_max;
}				t_map;

typedef struct s_data
{
	t_map	*map;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	*data;
}				t_vars;

typedef struct s_pixel {
	int	x;
	int	y;
}				t_pixel;

// images
void	next_image(t_vars *vars);

// keys
int		key_manager(int keycode, t_vars *vars);
int		destroy_win(t_vars *vars);

// main
void	free_arr_points(t_point **arr, int len);
int		free_vars(t_vars *vars);

// views
double	deg2rad(double degree);
void	fit_points_full_window(t_map *map, t_point **arr);

// map
t_map	*build_map(char *path);
void	set_map_plane(t_map *map, int a, int b, int c);
void	reset_points(t_map *map, t_point **arr);

// views
double	deg2rad(double degree);
void	fit_points_full_window(t_map *map, t_point **arr);
void	pixel_mapping_isometric(t_map *map, t_point **arr);

// tracing
void	my_mlx_pixel_put(t_data *img, int px, int py, int color);
void	bresenham_trace(t_data *img, t_point *p1, t_point *p2);
void	trace_map_points(t_data *img, t_map *map, t_point **arr);
void	trace_map_lines(t_data *img, t_map *map, t_point **arr);

#endif
