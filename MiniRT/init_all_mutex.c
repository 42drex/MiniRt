#include "minirt.h"

static int	init_move_mutex(t_move *m)
{	
	if (pthread_mutex_init(&m->m_up, NULL))
		return (1);
	if (pthread_mutex_init(&m->m_down, NULL))
	{
		mutex_destroy(1, &m->m_up);
		return (1);
	}
	if (pthread_mutex_init(&m->m_right, NULL))
	{
		mutex_destroy(2, &m->m_up, &m->m_down);
		return (1);
	}
	if (pthread_mutex_init(&m->m_left, NULL))
	{
		mutex_destroy(3, &m->m_up, &m->m_down, &m->right);
		return (1);
	}
	return (0);
}

int	init_all_mutex(t_win *w)
{
	if (pthread_mutex_init(&w->m_close, NULL))
		return (1);
	if (pthread_mutex_init(&w->m_pixel, NULL))
	{
		mutex_destroy(1, &w->m_close);
		return (1);
	}
	w->scene.m_pixel = w->m_pixel;
	if (pthread_mutex_init(&w->scene.cam.m_cam, NULL))
	{
		mutex_destroy(2, &w->m_close, &w->m_pixel);
		return (1);
	}
	if (init_move_mutex(&w->move))
	{
		mutex_destroy(3, &w->m_close, &w->m_pixel, &w->scene.cam.m_cam);
		return (1);
	}
	return (0);
}
