#include "parsingrt.h"

t_light	*realloc_light(t_light *old, int number)
{
	t_light	*new;

	new = malloc(sizeof(t_light) * (number + 1));
	if (!new)
		return (NULL);
	if (old)
	{
		ft_memcpy(new, old, sizeof(t_light) * number);
		free(old);
	}
	ft_bzero(&new[number], sizeof(t_light));
	return (new);
}

t_obj	*realloc_obj(t_obj *old, int number)
{
	t_obj	*new;

	new = malloc(sizeof(t_obj) * (number + 1));
	if (!new)
		return (NULL);
	if (old)
	{
		ft_memcpy(new, old, sizeof(t_obj) * number);
		free(old);
	}
	ft_bzero(&new[number], sizeof(t_obj));
	return (new);
}
