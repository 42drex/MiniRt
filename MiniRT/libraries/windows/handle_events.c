#include "events.h"
#include "windows.h"
#include <X11/X.h>

static int	handle_press(int key_pressed, void *data)
{
	t_win	*win;

	win = data;
	if (key_pressed == K_a || key_pressed == K_w
			|| key_pressed == K_d || key_pressed == K_s)
		ft_move_press(key_pressed, &win->move);
	if (key_pressed == ESC)
		free_windows(win);
	if (key_pressed == K_1 || key_pressed == K_2 || key_pressed == K_3)
		ft_resolution(key_pressed, win);
	if (key_pressed == K_m)
		show_or_hide_mouse(win);
	return (0);
}
	
static int	handle_release(int key_release, void *data)
{
	t_win	*win;

	win = data;
	if (key_release == K_a || key_release == K_w
			|| key_release == K_d || key_release == K_s)
		ft_move_release(key_release, &win->move);
	return (0);
}

void	handle_events(t_win *win)
{
		
	mlx_hook(win->win_ptr, MotionNotify, PointerMotionMask, mouse, win);
	mlx_hook(win->win_ptr, DestroyNotify, 0, free_windows, win);
	mlx_hook(win->win_ptr, KeyPress, KeyPressMask, handle_press, win);
	mlx_hook(win->win_ptr, KeyRelease, KeyReleaseMask, handle_release, win);
	mlx_loop_hook(win->mlx_ptr, frame_per_second, win);
	mlx_loop(win->mlx_ptr);
}
