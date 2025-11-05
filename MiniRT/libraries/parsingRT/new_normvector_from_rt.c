#include "parsingrt.h"

int	new_normvector_from_rt(t_vector *dir, char *line)
{
	char	**vector;
	int	i;

	vector = ft_split(line, ',');
	if (!vector)
		return (one_error(ERR_MALOC));
	remove_char(vector, ',');
	i = 0;
	while (vector[i])
		i++;
	if (i != 3)
		return (free_chartab(vector), one_error(ERR_VECTOR));
	if (!ft_atof(&dir->x, vector[0]) && (dir->x >= -1 && dir->x <= 1))
	{
		if (!ft_atof(&dir->y, vector[1]) && (dir->y >= -1 && dir->y <= 1))
		{
			if (!ft_atof(&dir->z, vector[2]) && (dir->z >= -1 && dir->z <= 1))
				return (free_chartab(vector), 0);
			return (free_chartab(vector), one_error(ERR_VECTOR));
		}
		return (free_chartab(vector), one_error(ERR_VECTOR));
	}
	return (free_chartab(vector), one_error(ERR_VECTOR));
}
