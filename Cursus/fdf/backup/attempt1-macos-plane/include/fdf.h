#ifndef FDF_H
#define FDF_H

#include <fcntl.h>
#include "libft.h"
#include "ft_printf.h"
#include <mlx.h>
#include <math.h>

#define HEIGHT 800
#define WIDTH 600
#define XCENTER (WIDTH / 2)
#define YCENTER (HEIGHT / 2)

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
	int col;
	int row;
	int height;
	int xyz[3];
	int	u;
	int	v;
} t_point;

typedef struct s_plane {
	int	a;
	int	b;
	int	c;
	int	n[3];
	int	u[3];
	int	v[3];
}				t_plane;

typedef struct s_map
{
	int		cols;
	int		rows;
	int		points;
	t_point	**arr;
	t_plane	*plane;
	int		u_min;
	int		u_max;
	int		v_min;
	int		v_max;
} 				t_map;

typedef struct s_data
{
	t_map	*map;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} 				t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	*data;
} 				t_vars;

// fdf
int		destroy_win(t_vars *vars);
int		close_win(int keycode, t_vars *vars);
void	free_arr_points(t_point **arr, int len);

// map
t_map	*build_map(char *path);
void	set_map_plane(t_map *map, int a, int b, int c);
void	reset_points(t_map *map, t_point **arr);


// mapview
void	fit_points_full_window(t_map *map, t_point **arr);
double	deg2rad(double degree);

// tracing
void my_mlx_pixel_put(t_data *img, int x, int y, int color);
void bresenham_trace(t_data *img, t_point *p1, t_point *p2);
void trace_map_points(t_data *img, t_map *map, t_point **arr);
void trace_map_lines(t_data *img, t_map *map, t_point **arr);

#endif
