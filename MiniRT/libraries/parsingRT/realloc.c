#include "parsingrt.h"

t_light	*realloc_light(t_light *old, int number)
{
	t_light	*new;
	int	i;

	i = 0;
	new = malloc(sizeof(t_light) * (number + 1));
	if (!new)
		return (free(old), NULL);
	i = -1;
	while (++i < number)
		new[i] = old[i];
	if (old)	
		free(old);
	return (new);
}
			
t_obj	*realloc_obj(t_obj *old, int number)
{
	t_obj	*new;
	int	i;

	i = 0;
	new = malloc(sizeof(t_obj) * (number + 1));
	if (!new)
		return (free(old), NULL);
	i = -1;
	while (++i < number)
		new[i] = old[i];
	free(old);
	return (new);
}
