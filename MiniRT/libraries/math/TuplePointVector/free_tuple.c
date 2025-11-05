#include "../mymath.h"

void	free_tuple(t_tuple **tuple)
{
	int	y;

	y = 0;
	while (y < YSIZE && tuple[y])
	{
		free(tuple[y]);
		y++;
	}
	free(tuple);
}
