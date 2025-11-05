#include "thread.h"
#include <pthread.h>

int	get_mutex_value(pthread_mutex_t *mutex, int *value)
{
	int	ret;

	pthread_mutex_lock(mutex);
	ret = *value;
	pthread_mutex_unlock(mutex);
	return (ret);
}

void	change_mutex_value(pthread_mutex_t *mutex, int *value, int new)
{
	pthread_mutex_lock(mutex);
	*value = new;
	pthread_mutex_unlock(mutex);
}
