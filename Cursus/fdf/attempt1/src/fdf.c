#include "fdf.h"

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		(void)vars;
//		if (vars)
//			free(vars);
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

int	main(int ac, char **av)
{
	t_vars	vars;
	char	*path;
	int	fd;
	uchar	*line;

	if (ac == 2)
	{
		path = av[1];
		ft_printf("cols: %d\n", fdf_map_cols(path));
		ft_printf("rows: %d\n", fdf_map_rows(path));
		fd = open(path, O_RDONLY);
		line = get_next_line(fd);
		ft_printf(">%s", line);
		while (line)
		{
			line = get_next_line(fd);
			ft_printf(">%s", line);
		}
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 800, 600, "FDF Viewer");
		mlx_key_hook(vars.win, close_win, &vars);
		mlx_hook(vars.win, ON_DESTROY, 0, destroy_win, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
