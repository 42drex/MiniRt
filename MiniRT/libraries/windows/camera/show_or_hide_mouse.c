#include "../windows.h"

void	show_or_hide_mouse(t_win *win)
{
	if (win->move.mouse)
	{
		win->move.mouse = 0;
		mlx_mouse_hide(win->mlx_ptr, win->win_ptr);
	}
	else
	{
		win->move.mouse = 1;
		mlx_mouse_show(win->mlx_ptr, win->win_ptr);
	}
}
