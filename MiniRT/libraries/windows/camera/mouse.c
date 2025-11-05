#include "../windows.h"

static t_vector new_vector_from_mouse(int x, int y, t_cam cam)
{
	float	rotX;
	float	rotY;
	t_vector	new;

	rotY = asin(cam.norm_dir.y) - (y * SENSI);
	rotX = atan2(cam.norm_dir.z, cam.norm_dir.x) - (x * SENSI);
	new.x = cos(rotY) * cos(rotX);
	new.y = sin(rotY);
	new.z = cos(rotY) * sin(rotX);
	return (new);
}

int	mouse(int x, int y, t_win *win)
{
	float		centerX;
	float		centerY;
	static struct timeval	last;
	struct timeval		current;
	t_cam			*cam;

	if (win->move.mouse)
		return (0);
	gettimeofday(&current, NULL);
	if (((current.tv_sec - last.tv_sec) * 1000)
		+ ((current.tv_usec - last.tv_usec) * 0.001) < 32)
		return (0);
	last = current;
	cam = &win->scene.cam;
	centerX = x - win->move.centerX;
	centerY = y - win->move.centerY;
	new_camera(win, cam->fov, cam->pos, new_vector_from_mouse(centerX, centerY, (*cam)));
	mlx_mouse_move(win->mlx_ptr, win->win_ptr, win->move.centerX, win->move.centerY);
	return (0);
}
