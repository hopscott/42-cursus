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
	int c;
	int r;
	int h;
	int x;
	int y;
	int z;
} t_point;

typedef struct s_map
{
	int cols;
	int rows;
	int points;
	t_point **arr_pt;
	int vertices;
	t_point **arr_v;
} t_map;

typedef struct s_data
{
	t_map *map;
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

typedef struct s_vars
{
	void *mlx;
	void *win;
	t_data *data;
	t_data *data_l;
	t_data *data_r;
} t_vars;

// fdf
int destroy_win(t_vars *vars);
int close_win(int keycode, t_vars *vars);

// map
int fdf_map_cols(char *path);
int fdf_map_rows(char *path);
void build_map_points(t_map map, t_point **arr, int fd);
t_map build_map(char *path);

// mapview
double deg2rad(double degree);
void dimetric_map_points(t_map *map, t_point **arr);
void isometric_map_points(t_map *map, t_point **arr);
void space_map_points(t_map *map, t_point **arr);

// tracing
void my_mlx_pixel_put(t_data *img, int x, int y, int color);
void trace_map_points(t_data *img, t_map *map);
void bresenham_trace(t_data *img, t_point *p1, t_point *p2);
void trace_map_lines(t_data *img, t_map *map);

#endif
