#include "../mymath.h"

void	chaining(t_mat4 *newm, const t_mat4 *translation, const t_mat4 *scaling,
		const t_mat4 *rotate)
{
	t_mat4	first;

	matrice_product(&first, translation, scaling);
	matrice_product(newm, &first, rotate);
}
