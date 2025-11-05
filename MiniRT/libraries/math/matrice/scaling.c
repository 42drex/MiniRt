#include "../mymath.h"

void	scaling(t_mat4 *newm, float x, float y, float z)
{
	mat4_set_row(newm, 0, x, 0.0f, 0.0f, 0.0f);
	mat4_set_row(newm, 1, 0.0f, y, 0.0f, 0.0f);
	mat4_set_row(newm, 2, 0.0f, 0.0f, z, 0.0f);
	mat4_set_row(newm, 3, 0.0f, 0.0f, 0.0f, 1.0f);
}
