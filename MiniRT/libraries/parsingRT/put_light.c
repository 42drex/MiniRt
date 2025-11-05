#include "parsingrt.h"

static int	asign_light(char **object, t_light *l)
{
	if (new_point_from_rt(&l->pos, object[1]))
		return (1);
	if (ft_atof(&l->ratio, object[2]))
		return (one_error(ERR_RATIO));
	if (l->ratio < 0 || l->ratio > 1)
		return (one_error(ERR_RATIO));
	if (new_color_from_rt(&l->color, object[3]))
		return (1);
	return (0);
}	

t_light	*put_light(char **object, t_light *l, int *number)
{
	l = realloc_light(l, *number);
	if (!l)
		return (null_error(ERR_MALOC));
	if (asign_light(object, &l[*number]))
	{
		free(l);
		return (NULL);
	}
	*number += 1;
	return (l);
}
