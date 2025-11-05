#include "../windows.h"

void	ft_move_press(int key, t_move *move)
{
	if (key == K_w)
		change_mutex_value(&move->m_up, &move->up, 1);
	else if (key == K_s)
		change_mutex_value(&move->m_down, &move->down, 1);
	else if (key == K_d)
		change_mutex_value(&move->m_right, &move->right, 1);
	else if (key == K_a)
		change_mutex_value(&move->m_left, &move->left, 1);
}

void	ft_move_release(int key, t_move *move)
{
	if (key == K_w)
		change_mutex_value(&move->m_up, &move->up, 0);
	else if (key == K_s)
		change_mutex_value(&move->m_down, &move->down, 0);
	else if (key == K_d)
		change_mutex_value(&move->m_right, &move->right, 0);
	else if (key == K_a)
		change_mutex_value(&move->m_left, &move->left, 0);
}
