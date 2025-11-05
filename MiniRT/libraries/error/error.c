#include "error.h"

static void	print_error(char *str)
{
	if (!ft_strcmp(str, ERR_MALOC))
		perror(ERR_MALOC);
	if (!ft_strcmp(str, ERR_POINT))
		perror(ERR_POINT);
	if (!ft_strcmp(str, ERR_VECTOR))
		perror(ERR_VECTOR);
	if (!ft_strcmp(str, ERR_COLOR))
		perror(ERR_COLOR);
	if (!ft_strcmp(str, ERR_HEIGHT))
		perror(ERR_HEIGHT);
	if (!ft_strcmp(str, ERR_RADIUS))
		perror(ERR_RADIUS);
	if (!ft_strcmp(str, ERR_FOV))
		perror(ERR_FOV);
	if (!ft_strcmp(str, ERR_RATIO))
		perror(ERR_RATIO);
}

int	one_error(char *str)
{
	print_error(str);
	return (1);
}

void	*null_error(char *str)
{
	print_error(str);
	return (NULL);
}
