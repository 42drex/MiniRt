#include "parsingrt.h"

static int	place_object(char **object, t_scene *s, int type)	
{
	if (type == 1)
	{
		if (put_cam(object, &s->cam))
			return (1);
	}
	else if (type == 2)
	{
		if (put_alight(object, &s->alight))
			return (1);
	}
	else if (type == 3)
	{
		s->light = put_light(object, s->light, &s->num_light);
		if (!s->light)
			return (1);
	}
	else if (type >= 4)
	{
		s->object = put_object(object, s->object, type, &s->num_obj);
		if (!s->object)
			return (1);
	}
	return (0);
}

int	asign_object_to_scene(char *line, t_scene *s)
{
	char	**object;
	int	type;

	if (line[0] == '\n')
		return (0);
	object = ft_split(line, ' ');
	remove_char(object, '\n');
	type = check_object(object); 
	if (type == 0)
	{
		if (object)
			free_chartab(object);
		return (1);
	}
	else
	{
		if (place_object(object, s, type))
		{
			free_chartab(object);
			return (1);
		}
	}
	free_chartab(object);
	return (0);
}	
