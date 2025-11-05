#include "windows.h"
#include <pthread.h>

int	frame_per_second(void	*data)
{
	t_win		*img;

	img = data;
	pthread_mutex_lock(&img->m_pixel);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
	pthread_mutex_unlock(&img->m_pixel);
	usleep(1000000 / FPS);
	return (0);
}
