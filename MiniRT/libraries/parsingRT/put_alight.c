#include "parsingrt.h"

int	put_alight(char **object, t_alight *al)
{
	if (ft_atof(&al->ratio, object[1]))
		return (one_error(ERR_RATIO));
	if (al->ratio < 0 || al->ratio > 1)
		return (one_error(ERR_RATIO));
	if (new_color_from_rt(&al->color, object[2]))
		return (1);
	return (0);
}
