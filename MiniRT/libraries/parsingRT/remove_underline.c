#include "parsingrt.h"

void	remove_char(char **object, char supp)
{
	int	i;
	int	j;

	i = 0;
	while (object[i])
	{
		j = 0;
		while (object[i][j])
		{
			if (object[i][j] == supp)
				object[i][j] = 0;
			j++;
		}
		i++;
	}
}
