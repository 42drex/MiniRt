#ifndef THREAD_H
# define THREAD_H

# include <pthread.h>
# include <stdarg.h>

int	get_mutex_value(pthread_mutex_t *mutex, int *value);

void	mutex_destroy(int count, ...);

void	change_mutex_value(pthread_mutex_t *mutex, int *value, int new);

# endif
