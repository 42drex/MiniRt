#include "../mymath.h"

void	translation(t_mat4 *newm, float x, float y, float z)
{
	mat4_set_row(newm, 0, 1.0f, 0.0f, 0.0f, x);
	mat4_set_row(newm, 1, 0.0f, 1.0f, 0.0f, y);
	mat4_set_row(newm, 2, 0.0f, 0.0f, 1.0f, z);
	mat4_set_row(newm, 3, 0.0f, 0.0f, 0.0f, 1.0f);
}
