#include "../mymath.h"

int	matrice_is_equal(const t_mat4 *a, const t_mat4 *b)
{
	__m128	eps;
	__m128	sign_mask;
	__m128	diff;
	__m128	abs_diff;
	__m128	cmp;
	int		idx;

	eps = _mm_set1_ps(EPSILON);
	sign_mask = _mm_set1_ps(-0.0f);
	idx = 0;
	while (idx < 4)
	{
		diff = _mm_sub_ps(a->simd[idx], b->simd[idx]);
		abs_diff = _mm_andnot_ps(sign_mask, diff);
		cmp = _mm_cmple_ps(abs_diff, eps);
		if (_mm_movemask_ps(cmp) != 0xF)
			return (0);
		idx++;
	}
	return (1);
}

void	matrice_product(t_mat4 *newm, const t_mat4 *a, const t_mat4 *b)
{
	matrice_product_avx(newm, a, b);
}

static t_vector	get_right_vector(t_vector dir)
{
	t_vector	up;
	t_vector	right;

	up.x = 0.0f;
	up.y = 1.0f;
	up.z = 0.0f;
	up.w = 0.0f;
	right = cross(up, dir);
	right = normalize(right);
	return (right);
}

static t_vector	get_up_vector(t_vector dir, t_vector right)
{
	t_vector	up;

	up = cross(dir, right);
	return (up);
}

void	asign_matrice(t_mat4 *tab, t_point pos, t_vector dir)
{
	t_vector	right;
	t_vector	up;

	right = get_right_vector(dir);
	up = get_up_vector(dir, right);
	tab->a[0][0] = right.x;
	tab->a[0][1] = up.x;
	tab->a[0][2] = dir.x;
	tab->a[0][3] = pos.x;
	tab->a[1][0] = right.y;
	tab->a[1][1] = up.y;
	tab->a[1][2] = dir.y;
	tab->a[1][3] = pos.y;
	tab->a[2][0] = right.z;
	tab->a[2][1] = up.z;
	tab->a[2][2] = dir.z;
	tab->a[2][3] = pos.z;
	tab->a[3][0] = 0.0f;
	tab->a[3][1] = 0.0f;
	tab->a[3][2] = 0.0f;
	tab->a[3][3] = 1.0f;
}
				