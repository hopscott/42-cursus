/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:47:18 by swillis           #+#    #+#             */
/*   Updated: 2022/03/24 17:27:11 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"
# include <mlx.h>
# include <math.h>

# include <stdio.h> // <==== X

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
	int		x;
	int		y;
	int		z;
	double	px;
	double	py;
}			t_point;

typedef struct s_mat {
	int		r;
	int		c;
	double	**tbl;
}				t_mat;

typedef struct s_colour
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	dec;
}	t_colour;

typedef struct s_map
{
	int			cols;
	int			rows;
	int			points;
	t_point		**arr;
	int			z_min;
	int			z_max;
	t_colour	min_colour;
	t_colour	max_colour;
	int			r_max;
	int			g_max;
	int			b_max;
	double		alpha;
	double		beta;
	double		theta;
	t_mat		*rx;
	t_mat		*ry;
	t_mat		*rz;
	t_mat		*r;
	double		dx;
	double		dy;
	int			zoom;
	double		px_min;
	double		px_max;
	double		py_min;
	double		py_max;
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

typedef struct s_trace {
	int		dy;
	int		dx;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		z0;
	int		z1;
	int		r0;
	int		g0;
	int		b0;
	int		r1;
	int		g1;
	int		b1;
	double	h;
	int		steps;
}				t_trace;

// fitting
void	find_map_heights(t_map *map, t_point **arr);

// keys
int		key_manager(int keycode, t_vars *vars);
int		destroy_win(t_vars *vars);

// main
void	free_arr_points(t_point **arr, int len);
int		free_vars(t_vars *vars);

// views
double	deg2rad(double degree);
void	find_origin_point(t_map *map, t_point **arr);
void	find_furthest_point(t_map *map, t_point **arr);
void	fit_points_full_window(t_map *map, t_point **arr);

// map
t_map	*build_map(char *path);

// tracing
void	next_image(t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int px, int py, int color);
void	trace_map_points(t_data *data, t_map *map, t_point **arr);
void	trace_map_lines(t_data *data, t_map *map, t_point **arr);

// rotations
void	basic_rotate(t_map *map, double alpha, double beta, double theta);

// shifts
void	recenter_xyz(t_map *map, t_point **arr);
void	uncenter_xyz(t_map *map, t_point **arr);
void	basic_translate(t_map *map, double dx, double dy);
void	basic_zoom(t_map *map, int zoom);

// matrices
t_mat	*free_matrix(t_mat *mat, int rows);
t_mat	*init_matrix(int r, int c);
void	set_matrix(double arr[], t_mat *mat);
void	matrix_multipy(t_mat *m1, t_mat *m2, t_mat *res);

// lines
void	bresenham_trace(t_data *data, t_point *p0, t_point *p1);

#endif
