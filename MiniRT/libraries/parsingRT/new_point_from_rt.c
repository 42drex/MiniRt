#include "parsingrt.h"

int	new_point_from_rt(t_point *pos, char *line)
{
	char	**point;
	int	i;

	point = ft_split(line, ',');
	if (!point)
		return (one_error(ERR_MALOC));
	remove_char(point, ',');
	i = 0;
	while (point[i])
		i++;
	if (i != 3)
		return (free_chartab(point), one_error(ERR_POINT));
	if (!ft_atof(&pos->x, point[0]))
	{
		if (!ft_atof(&pos->y, point[1]))
		{
			if (!ft_atof(&pos->z, point[2]))
				return (free_chartab(point), 0);
			return (free_chartab(point), one_error(ERR_POINT));
		}
		return (free_chartab(point), one_error(ERR_POINT));
	}
	return (free_chartab(point), one_error(ERR_POINT));
}

				
