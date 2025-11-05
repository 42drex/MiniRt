#include "parsingrt.h"

static int	asign_cylindre(char **object, t_obj *o)
{
	o->type = CYLINDRE;
	if (new_point_from_rt(&o->origin, object[1]))
		return (1);
	if (new_normvector_from_rt(&o->dir, object[2]))
		return (1);
	if (ft_atof(&o->radius, object[3]))
		return (one_error(ERR_RADIUS));
	if (o->radius < 0)
		return (one_error(ERR_RADIUS));
	if (ft_atof(&o->height, object[4]))
		return (one_error(ERR_HEIGHT));
	if (o->height < 0)
		return (one_error(ERR_HEIGHT));
	if (new_color_from_rt(&o->color, object[5]))
		return (1);
	return (0);
}

static int	asign_plane(char **object, t_obj *o)
{
	o->type = PLAN;
	if (new_point_from_rt(&o->origin, object[1]))
		return (1);
	if (new_normvector_from_rt(&o->dir, object[2]))
		return (1);
	if (new_color_from_rt(&o->color, object[3]))
		return (1);
	return (0);
}

static int	asign_sphere(char **object, t_obj *o)
{
	o->type = SPHERE;
	if (new_point_from_rt(&o->origin, object[1]))
		return (1);
	if (ft_atof(&o->radius, object[2]))
		return (one_error(ERR_RADIUS));
	if (o->radius < 0)
		return (one_error(ERR_RADIUS));
	if (new_color_from_rt(&o->color, object[3]))
		return (1);
	translation(&o->translation, o->origin.x, o->origin.y, o->origin.z);
	/* precompute inverse and inverse-transpose */
	if (!inverse(&o->inv, &o->translation))
	{
		mat4_set_row(&o->inv, 0, 1, 0, 0, 0);
		mat4_set_row(&o->inv, 1, 0, 1, 0, 0);
		mat4_set_row(&o->inv, 2, 0, 0, 1, 0);
		mat4_set_row(&o->inv, 3, 0, 0, 0, 1);
	}
	o->inv_t = o->inv;
	return (0);
}

static int	asign_object(char **object, t_obj *o, int type)
{
	if (type == 4)
		if (asign_sphere(object, o))
			return (1);
	if (type == 5)
		if (asign_cylindre(object, o))
			return (1);
	if (type == 6)
		if (asign_plane(object, o))
			return (1);
	return (0);
}

t_obj	*put_object(char **object, t_obj *o, int type, int *number)
{
	o = realloc_obj(o, *number);
	if (!o)
		return (null_error(ERR_MALOC));
	if (asign_object(object, &o[*number], type))
	{
		free(o);
		return (NULL);
	}
	*number += 1;
	return (o);
}
