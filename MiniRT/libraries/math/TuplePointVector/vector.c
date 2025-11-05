#include "../mymath.h"

/* ===== Fonctions SIMD internes (static inline) ===== */

static inline __m128	normalize_vector_simd(__m128 vec)
{
	__m128	dot;
	__m128	inv_mag;

	vec = _mm_blend_ps(vec, _mm_setzero_ps(), 0x8);
	dot = _mm_dp_ps(vec, vec, 0x71);
	inv_mag = _mm_set1_ps(1.0f / sqrtf(_mm_cvtss_f32(dot)));
	vec = _mm_mul_ps(vec, inv_mag);
	return (_mm_blend_ps(vec, _mm_setzero_ps(), 0x8));
}

static inline float	dot_vector_simd(__m128 a, __m128 b)
{
	__m128	dot;

	dot = _mm_dp_ps(a, b, 0x71);
	return (_mm_cvtss_f32(dot));
}

static inline __m128	cross_vector_simd(__m128 a, __m128 b)
{
	__m128	a_yzx;
	__m128	b_yzx;
	__m128	result;

	a_yzx = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1));
	b_yzx = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1));
	result = _mm_mul_ps(a, b_yzx);
	a_yzx = _mm_mul_ps(a_yzx, b);
	result = _mm_sub_ps(result, a_yzx);
	result = _mm_shuffle_ps(result, result, _MM_SHUFFLE(3, 0, 2, 1));
	return (_mm_blend_ps(result, _mm_setzero_ps(), 0x8));
}

static inline __m128	neg_vector_simd(__m128 a)
{
	__m128	result;

	result = _mm_mul_ps(a, _mm_set1_ps(-1.0f));
	return (_mm_blend_ps(result, _mm_setzero_ps(), 0x8));
}

/* ===== API publique ===== */

float	magnitude(t_vector vector)
{
	__m128	vec;
	__m128	dot;

	vec = vector.raw;
	dot = _mm_dp_ps(vec, vec, 0x71);
	return (sqrtf(_mm_cvtss_f32(dot)));
}

t_vector	normalize(t_vector vector)
{
	float		mag;
	t_vector	result;

	mag = magnitude(vector);
	if (isequal_EPS(mag, 0.0f))
		return (vector);
	result.raw = normalize_vector_simd(vector.raw);
	result.w = 0.0f;
	return (result);
}

float	dot_product(t_vector a, t_vector b)
{
	return (dot_vector_simd(a.raw, b.raw));
}

t_vector	cross(t_vector a, t_vector b)
{
	t_vector	result;

	result.raw = cross_vector_simd(a.raw, b.raw);
	result.w = 0.0f;
	return (result);
}

t_vector	neg_vector(t_vector a)
{
	t_vector	result;

	result.raw = neg_vector_simd(a.raw);
	result.w = 0.0f;
	return (result);
}
