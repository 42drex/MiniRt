#include "../windows.h"

void	*thread_movement(void	*window)
{
	t_win		*win;
	t_cam		*cam;
	t_vector	right;
	
	win = window;
	cam = &win->scene.cam;
	while (!get_mutex_value(&win->m_close, &win->close))
	{	
		if (get_mutex_value(&win->move.m_up, &win->move.up))
			new_camera(win, cam->fov, new_point_forward(cam->pos, cam->norm_dir), cam->norm_dir);
		if (get_mutex_value(&win->move.m_down, &win->move.down))
			new_camera(win, cam->fov, new_point_backward(cam->pos, cam->norm_dir), cam->norm_dir);
		if (get_mutex_value(&win->move.m_right, &win->move.right))
		{
			right = cross((t_vector){ .x = 0.0f, .y = 0.1f, .z = 0.0f, .w = 0.0f }, cam->norm_dir);
			new_camera(win, cam->fov, new_point_forward(cam->pos, right), cam->norm_dir);
		}
		if (get_mutex_value(&win->move.m_left, &win->move.left))
		{
			right = neg_vector(cross((t_vector){ .x = 0.0f, .y = 0.1f, .z = 0.0f, .w = 0.0f }, cam->norm_dir));
			new_camera(win, cam->fov, new_point_forward(cam->pos, right), cam->norm_dir);
		}
		usleep(32000);
	}
	return (window);
}
