#include "../mymath.h"

static inline __m128	tuple_to_m128(const t_tuple *tuple)
{
	return (tuple->raw);
}

static inline t_tuple	m128_to_tuple(__m128 vec)
{
	t_tuple	result;

	result.raw = vec;
	return (result);
}

float	mag_tuple(t_tuple tuple)
{
	__m128	vec;
	__m128	dot;

	vec = tuple_to_m128(&tuple);
	dot = _mm_dp_ps(vec, vec, 0xFF);
	return (sqrtf(_mm_cvtss_f32(dot)));
}

t_tuple	norm_tuple(t_tuple tuple)
{
	float	magnitude;
	__m128	vec;
	__m128	scale;

	magnitude = mag_tuple(tuple);
	if (isequal_EPS(magnitude, 0.0f))
		return (tuple);
	vec = tuple_to_m128(&tuple);
	scale = _mm_set1_ps(1.0f / magnitude);
	vec = _mm_mul_ps(vec, scale);
	return (m128_to_tuple(vec));
}
