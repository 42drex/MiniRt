#include "thread.h"

void	mutex_destroy(int count, ...)
{
	pthread_mutex_t	*m;
	va_list		ap;
	int		i;
	
	i = 0;
	va_start(ap, count);
	while (i < count)
	{
		m = va_arg(ap, pthread_mutex_t *);
		pthread_mutex_destroy(m);
		i++;
	}
	va_end(ap);
}
