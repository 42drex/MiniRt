#include "../mymath.h"

t_vector	tuple_to_vector(t_tuple a)
{
	t_vector	new;
	__m128		mask;

	// Copier les données SIMD et forcer w = 0
	new.raw = a.raw;
	mask = _mm_castsi128_ps(_mm_set_epi32(0, -1, -1, -1));
	new.raw = _mm_and_ps(new.raw, mask);
	new.w = 0.0f;
	return (new);
}

t_point	tuple_to_point(t_tuple a)
{
	t_point	new;

	// Copie directe via SIMD et force w = 1 pour un point
	new.raw = a.raw;
	new.w = 1.0f;
	return (new);
}

t_tuple	tuple(void *tuple, int type)
{
	t_point		*point;
	t_vector	*vector;
	t_tuple	new;
	
	if (!type)
	{
		vector = tuple;
		new.x = vector->x;
		new.y = vector->y;
		new.z = vector->z;
		new.w = 0.0f;
	}
	else
	{
		point = tuple;
		new.x = point->x;
		new.y = point->y;
		new.z = point->z;
		new.w = 1;
	}
	return (new);
}

t_tuple	**new_tuple_2tab(void)
{	
	t_tuple	**ray;
	int		y;
	
	ray = malloc(sizeof(t_vector *) * YSIZE);
	if (!ray)
		return (NULL);
	y =  0;
	while (y < YSIZE)
	{
		ray[y] = malloc(sizeof(t_vector) * XSIZE);
		if (!ray[y])
		{
			free_tuple(ray);
			return (NULL);
		}
		y++;
	}
	return (ray);
}
