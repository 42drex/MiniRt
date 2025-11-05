#include "../mymath.h"

void	shearing(t_mat4 *newm, t_shearing a)
{
	mat4_set_row(newm, 0, 1.0f, a.x_y, a.x_z, 0.0f);
	mat4_set_row(newm, 1, a.y_x, 1.0f, a.y_z, 0.0f);
	mat4_set_row(newm, 2, a.z_x, a.z_y, 1.0f, 0.0f);
	mat4_set_row(newm, 3, 0.0f, 0.0f, 0.0f, 1.0f);
}
