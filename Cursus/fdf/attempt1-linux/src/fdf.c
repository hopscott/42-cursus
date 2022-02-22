#include "fdf.h"

int	close_win(int keycode, t_vars *vars)
{
//	if (keycode == 53) //macos
	if (keycode == 65307) //linux
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

//int	render_next_frame(t_vars *vars)
//{
//	vars.map = 
//	
//}


int	main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;
//	char	*path;
//	int	fd;
//	uchar	*line;

	if (ac == 2)
	{
		// file ===============
		(void)av;
//		path = av[1];
//		ft_printf("cols: %d\n", fdf_map_cols(path));
//		ft_printf("rows: %d\n", fdf_map_rows(path));
//		fd = open(path, O_RDONLY);
//		line = get_next_line(fd);
//		ft_printf(">%s", line);
//		while (line)
//		{
//			line = get_next_line(fd);
//			ft_printf(">%s", line);
//		}
		// ====================

		// init
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, HEIGHT, WIDTH, "FDF Viewer");
		
		// img
		img = *vars.data;
		img.img = mlx_new_image(vars.mlx, HEIGHT, WIDTH);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		my_mlx_pixel_put(&img, HEIGHT/2, WIDTH/2, 0x00FF0000);
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
