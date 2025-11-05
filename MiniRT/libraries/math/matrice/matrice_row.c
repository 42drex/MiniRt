#include "../mymath.h"

void	mat4_set_row(t_mat4 *mat, int index, float a, float b, float c, float d)
{
	__m128	row;

	row = _mm_set_ps(d, c, b, a);
	mat->simd[index] = row;
}
