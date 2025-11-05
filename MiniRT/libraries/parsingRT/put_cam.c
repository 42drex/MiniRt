#include "parsingrt.h"
#include <pthread.h>

int	put_cam(char **object, t_cam *c)
{
	if (new_point_from_rt(&c->pos, object[1]))
		return (1);
	if (new_normvector_from_rt(&c->norm_dir, object[2]))
		return (1);
	if (ft_atof(&c->fov, object[3]))
		return (one_error(ERR_FOV));
	if (c->fov < 0 || c->fov > 180)
		return (one_error(ERR_FOV));
	asign_matrice(&c->matrice, c->pos, c->norm_dir);
	c->aspect = (float)YSIZE / (float)XSIZE;
	c->halfX = tan(radian(c->fov) * 0.5);
	c->halfY = c->halfX * c->aspect;
	return (0);
}
