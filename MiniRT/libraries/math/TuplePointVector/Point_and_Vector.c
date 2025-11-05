#include "../mymath.h"

/* ===== Fonctions SIMD internes (static inline) ===== */

static inline __m128	add_point_vector_simd(__m128 point, __m128 vector)
{
	return (_mm_add_ps(point, vector));
}

static inline __m128	sub_point_vector_simd(__m128 point, __m128 vector)
{
	return (_mm_sub_ps(point, vector));
}

/* ===== API publique ===== */

t_point	new_point_forward(t_point point, t_vector vector)
{
	t_point	new;

	new.raw = add_point_vector_simd(point.raw, vector.raw);
	return (new);
}

t_point	new_point_backward(t_point point, t_vector vector)
{
	t_point	new;

	new.raw = sub_point_vector_simd(point.raw, vector.raw);
	return (new);
}

t_vector	vector_from_points(t_point a, t_point b)
{
	t_vector	new;

	new.raw = sub_point_vector_simd(a.raw, b.raw);
	new.w = 0.0f;
	return (new);
}

t_vector	substract_vector(t_vector a, t_vector b)
{
	t_vector	new;

	new.raw = sub_point_vector_simd(a.raw, b.raw);
	new.w = 0.0f;
	return (new);
}
