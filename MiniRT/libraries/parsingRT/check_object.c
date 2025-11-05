#include "parsingrt.h"

static int	test_obj(int type, int i)
{
	
	if (type == 4)
		if (i != 3)
		       return (0);	
	if (type == 5)
		if (i != 5)
		       return (0);	
	if (type == 6)
		if (i != 3)
		       return (0);
	return (1);
}

static int	set_type(char *line)
{
	if (!ft_strcmp(line, "C"))
		return (1);
	if (!ft_strcmp(line, "A"))
		return (2);
	if (!ft_strcmp(line, "L"))
		return (3);
	if (!ft_strcmp(line, "sp"))
		return (4);
	if (!ft_strcmp(line, "cy"))
		return (5);
	if (!ft_strcmp(line, "pl"))
		return (6);
	return (0);
}

int	check_object(char **object)
{
	int	type;
	int	i;

	i = 0;
	type = set_type(object[0]);
	if (type == 0)
		return (0);
	while (object[i + 1])
		i++;
	if (type == 1)
		if (i != 3)
		       return (0);	
	if (type == 2)
		if (i != 2)
		       return (0);	
	if (type == 3)
		if (i != 3)
		       return (0);	
	if (type >= 4)
		if (!test_obj(type, i))
		       return (0);
	return (type);
}	
