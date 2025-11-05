#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include "../libft/libft.h"

# define ERR_MALOC "Malloc error, check memory space"
# define ERR_POINT "Point error, check your .rt file"
# define ERR_VECTOR "Vector error, check your .rt file"
# define ERR_COLOR "Collor error, check your .rt file"
# define ERR_RADIUS "Radius error, check your .rt file"
# define ERR_HEIGHT "Height error, check your .rt file"
# define ERR_RATIO "Ratio error, check your .rt file"
# define ERR_FOV "FOV error, check your .rt file"

int	one_error(char *str);
void	*null_error(char *str);

# endif
