#include "../mymath.h"

static float	get_sign(int x, int y)
{
	int	sum;

	sum = x + y;
	if ((sum % 2) == 0)
		return (1.0f);
	return (-1.0f);
}

float	cofactor(const t_mat4 *a, int x, int y, int size)
{
	t_mat4	tmp;
	t_sub	sub;
	float	det;
	float	sign;

	sub.x = x;
	sub.y = y;
	sub.size = size;
	submatrix(&tmp, a, sub);
	det = determinant(&tmp, size - 1);
	sign = get_sign(x, y);
	return (sign * det);
}

float	determinant(const t_mat4 *a, int size)
{
	int	i;
	float	res;
	t_sub	sub;
	t_mat4	tmp;
	float	sign;

	if (size < 2)
		return (0.0f);
	if (size == 2)
		return (a->a[0][0] * a->a[1][1] - a->a[0][1] * a->a[1][0]);
	i = 0;
	res = 0.0f;
	while (i < size)
	{
		sub.x = 0;
		sub.y = i;
		sub.size = size;
		submatrix(&tmp, a, sub);
		sign = get_sign(0, i);
		res = res + sign * a->a[0][i] * determinant(&tmp, size - 1);
		i++;
	}
	return (res);
}

int	inverse(t_mat4 *newm, const t_mat4 *a)
{
	float	deter;
	int		x;
	int		y;

	deter = determinant(a, 4);
	if (isequal_EPS(deter, 0.0f))
		return (0);
	deter = 1.0f / deter;
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			newm->a[y][x] = cofactor(a, x, y, 4) * deter;
			y++;
		}
		x++;
	}
	return (1);
}

