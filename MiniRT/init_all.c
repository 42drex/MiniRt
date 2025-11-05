#include "minirt.h"
#include <pthread.h>

static void	init_scene(t_scene *scene)
{
	scene->img = NULL;
	scene->num_obj = 0;
	scene->num_light = 0;
	scene->resolution = 2;
}
	
static void	init_move(t_move *move)
{
	move->centerX = XSIZE / 2;
	move->centerY = YSIZE / 2;
	move->mouse = 1;
	move->up = 0;
	move->down = 0;
	move->left = 0;
	move->right = 0;
}

int	init_all(t_win *win)
{
	win->mlx_ptr = NULL;
	win->win_ptr = NULL;
	win->img = NULL;
	win->close = 0;
	init_move(&win->move);
	init_scene(&win->scene);
	if (init_all_mutex(win))
		return (1);
	return (0);
}
