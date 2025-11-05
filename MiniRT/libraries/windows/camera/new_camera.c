#include "../windows.h"

void	new_camera(t_win *win, float fov, t_point pos, t_vector dir)
{
	t_cam	*cam;

	cam = &win->scene.cam;
	pthread_mutex_lock(&cam->m_cam);
	cam->pos = pos;
	cam->norm_dir = dir;
	asign_matrice(&cam->matrice, pos, cam->norm_dir);
	cam->fov = fov;
	cam->aspect = (float)YSIZE / (float)XSIZE;
	cam->halfX = tan(radian(fov) * 0.5);
	cam->halfY = cam->halfX * cam->aspect;
	pthread_mutex_unlock(&cam->m_cam);
	gen_img_from_cam(&win->scene);
	return ;
}
