#include "windows.h"

int	free_windows(t_win *win)
{			
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	change_mutex_value(&win->m_close, &win->close, 1);
	exit (1);
}
