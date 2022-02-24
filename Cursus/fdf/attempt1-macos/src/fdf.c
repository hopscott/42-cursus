#include "fdf.h"

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 53) //macos
//	if (keycode == 65307) //linux
	{
		mlx_destroy_window(vars->mlx, vars->win);
		(void)vars;
		exit(0);
	}
	return (0);
}

int	fdf_map_cols(char *path)
{
	int	x;
	int	fd;
	uchar	*str;

	fd = open(path, O_RDONLY);
	if (!fd)
		return (-1);
	str = get_next_line(fd);
	close(fd);
	x = ft_wordcount(str, ' ');
	free(str);
	return (x);
}

int	fdf_map_rows(char *path)
{
	int	y;
	int	fd;

	fd = open(path, O_RDONLY);
	if (!fd)
		return (-1);
	y = 0;
	while (get_next_line(fd))
		y++;
	close(fd);
	return (y);
}

int	destroy_win(t_vars *vars)
{
	(void)vars;
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	bresenham_trace(t_data *img, t_point p1, t_point p2)
{
	int	x;
	int	y;
	int	m;
	int	slope_error;

	if (p1.x < p2.x)
	{
		m = 2 * (p2.y - p1.y);
		slope_error = m - (p2.x - p1.x);
		x = p1.x;
		y = p1.y;
		while (x <= p2.x)
		{
			my_mlx_pixel_put(img, x, y, 0xFFFFFF);
			slope_error += m;
			if (slope_error >= 0)
			{
				y++;
				slope_error -= 2 * (p2.x - p1.x);
			}
			x++;
		}
	}
}

t_point	*build_map_array(t_map map, t_point *arr, int fd)
{
	int	i;
	int	j;
	uchar	**row;
	uchar	*line;
	t_point	pt;

	i = 0;
	line = get_next_line(fd);
	while (line && (i < map.rows))
	{
		row = ft_split(line, ' ');
		j = 0;
		while (j < map.cols)
		{
			pt.x = i;
			pt.y = j;
			pt.z = ft_atoi(row[j]);
			arr[i + j] = pt;
			j++;
		}
		i++;
		line = get_next_line(fd);
	}
	return (arr);
}

t_map	build_map(char *path)
{
	int	fd;
	t_map map;
	t_point	*arr;

	map.cols = fdf_map_cols(path);
	map.rows = fdf_map_rows(path);
	map.points = map.cols * map.rows;
	arr = malloc(sizeof(t_point) * map.points);
	if (!arr)
	{
		map.arr = 0;
		return (map);
	}
	fd = open(path, O_RDONLY);
	arr = build_map_array(map, arr, fd);
	close(fd);
	map.arr = arr;
	return (map);
}

//int	render_next_frame(t_vars *vars)
//{
//	vars.map = 
//	
//}


int	main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;
	t_map	map;
	int	i;

//	char	*path;
//	int	fd;
//	uchar	*line;

	if (ac == 2)
	{
		// file ===============
		map = build_map(av[1]);

		// init
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, HEIGHT, WIDTH, "FDF Viewer");
		
		// img
//		img = *vars.data;
		img.img = mlx_new_image(vars.mlx, HEIGHT, WIDTH);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

		i = 0;
		while (i + 1 < map.points)
		{
			bresenham_trace(&img, map.arr[i], map.arr[i + 1]);
			i++;
		}
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

//		mlx_loop_hook(vars.mlx, render_next_frame, &vars);

		// esc keys
		mlx_key_hook(vars.win, close_win, &vars);
		mlx_hook(vars.win, ON_DESTROY, 0, destroy_win, &vars);

		// loop
		mlx_loop(vars.mlx);
	}
	return (0);
}
