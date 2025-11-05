#include "../mymath.h"

static void	fill_rest(float *dst, int start)
{
	while (start < 4)
	{
		dst[start] = 0.0f;
		start++;
	}
}

static void	fill_sub_row(float *dst, const float *src, int skip_y, int size)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (j < size)
	{
		if (j != skip_y)
		{
			dst[k] = src[j];
			k++;
		}
		j++;
	}
	fill_rest(dst, k);
}

static void	clear_remaining_rows(t_mat4 *newm, int row)
{
	while (row < 4)
	{
		newm->a[row][0] = 0.0f;
		newm->a[row][1] = 0.0f;
		newm->a[row][2] = 0.0f;
		newm->a[row][3] = 0.0f;
		row++;
	}
}

void	submatrix(t_mat4 *newm, const t_mat4 *a, t_sub sub)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < sub.size)
	{
		if (i != sub.x)
		{
			fill_sub_row(newm->a[k], a->a[i], sub.y, sub.size);
			k++;
		}
		i++;
	}
	clear_remaining_rows(newm, k);
}
