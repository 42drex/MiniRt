#include "object.h"

t_obj	new_sphere(t_point origin, float radius)
{
	t_obj	new;

	new.type = SPHERE;
	new.origin = origin;
	new.radius = radius;
	translation(&new.translation, origin.x, origin.y, origin.z);
	/* precompute inverse and inverse-transpose for faster intersections */
	if (!inverse(&new.inv, &new.translation))
	{
		/* if inversion fails, zero the matrix to keep defined behavior */
		mat4_set_row(&new.inv, 0, 1, 0, 0, 0);
		mat4_set_row(&new.inv, 1, 0, 1, 0, 0);
		mat4_set_row(&new.inv, 2, 0, 0, 1, 0);
		mat4_set_row(&new.inv, 3, 0, 0, 0, 1);
	}
	/* inv_t not currently used heavily, but keep identity transpose for now */
	new.inv_t = new.inv;
	return (new);
}
