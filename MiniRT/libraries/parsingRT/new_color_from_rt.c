#include "parsingrt.h"

static int	only_digit(char *line)
{
	int	i;

	i = 1;
	if (line[0] != '+' && line[0] != '-' && !ft_isdigit(line[0]))
		return (1);
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (1);
		i++;
	}
	return (0);
}	

unsigned int	check_rgb(int *r, int *g, int *b, char **c)
{
	*r = ft_atoi(c[0]);
	if (*r < 0 || *r > 255)
		return (1);
	*g = ft_atoi(c[1]);
	if (*g < 0 || *g > 255)
		return (1);
	*b = ft_atoi(c[2]);
	if (*b < 0 || *b > 255)
		return (1);
	return (0);
}

int	new_color_from_rt(unsigned int *color, char *object)
{
	char	**c;
	int	i;
	int	r;
	int	g;
	int	b;

	c = ft_split(object, ',');
	if (!color)
		return (one_error(ERR_MALOC));
	remove_char(c, ',');
	i = 0;
	while (c[i])
	{
		if (only_digit(c[i]))
			return (free_chartab(c), one_error(ERR_COLOR));	
		i++;
	}
	if (i != 3)
		return (free_chartab(c), one_error(ERR_COLOR));
	if (check_rgb(&r, &g, &b, c))
		return (free_chartab(c), one_error(ERR_COLOR));
	*color = gen_trgb(0, r, g, b);
	return (0);
}
