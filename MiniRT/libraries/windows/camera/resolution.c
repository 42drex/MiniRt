#include "../windows.h"

void	ft_resolution(int key, t_win *win)
{
	if (key == K_1)
		win->scene.resolution = 1;
	else if (key == K_2)
		win->scene.resolution = 5;
	else if (key == K_3)
		win->scene.resolution = 10;
	gen_img_from_cam(&win->scene);
}
