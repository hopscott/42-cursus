// Header here
#include "ft_printf.h"
#include <mlx.h>

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	mouse_hook(int x, int y, t_vars *vars)
{
	ft_printf("=====\nx: %d\n", x);
	ft_printf("y: %d\n=====\n", y);
	(void)vars;
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "FDF Viewer");
	mlx_hook(vars.win, ON_KEYDOWN, 1L<<0, close_win, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
