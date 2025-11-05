#include "windows.h"

int	create_window(t_win *win, char *name)
{
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		return (1);
	win->win_ptr = mlx_new_window(win->mlx_ptr, XSIZE, YSIZE, name);
	if (!win->win_ptr)
		return (1);
	win->img = mlx_new_image(win->mlx_ptr, XSIZE, YSIZE);
	if (!win->img)
		return (1);
	win->scene.img = win->img;
	return (0);
}
