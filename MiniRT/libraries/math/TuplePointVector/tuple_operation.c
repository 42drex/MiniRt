#include "../mymath.h"

/* ===== Fonctions SIMD internes (static inline) ===== */

static inline __m128	add_tuple_simd(__m128 a, __m128 b)
{
	return (_mm_add_ps(a, b));
}

static inline __m128	sub_tuple_simd(__m128 a, __m128 b)
{
	return (_mm_sub_ps(a, b));
}

static inline __m128	mul_tuple_simd(__m128 a, float scalar)
{
	return (_mm_mul_ps(a, _mm_set1_ps(scalar)));
}

static inline __m128	neg_tuple_simd(__m128 a)
{
	return (_mm_mul_ps(a, _mm_set1_ps(-1.0f)));
}

/* ===== API publique ===== */

t_tuple	add_tupple(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.raw = add_tuple_simd(a.raw, b.raw);
	return (result);
}

t_tuple	sub_tupple(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.raw = sub_tuple_simd(a.raw, b.raw);
	return (result);
}

t_tuple	prod_tuple(t_tuple a, float product)
{
	t_tuple	result;

	result.raw = mul_tuple_simd(a.raw, product);
	return (result);
}

t_tuple	neg_tupple(t_tuple a)
{
	t_tuple	result;

	result.raw = neg_tuple_simd(a.raw);
	return (result);
}

t_tuple	matrice_to_tuple(const t_mat4 *a, t_tuple tuple)
{
	t_tuple	result;
	__m128	mul0;
	__m128	mul1;
	__m128	mul2;
	__m128	mul3;

	// Technique inspirée de "lag" : multiply + hadd
	mul0 = _mm_mul_ps(a->simd[0], tuple.raw);
	mul1 = _mm_mul_ps(a->simd[1], tuple.raw);
	mul2 = _mm_mul_ps(a->simd[2], tuple.raw);
	mul3 = _mm_mul_ps(a->simd[3], tuple.raw);
	
	// Combine avec hadd : fait toutes les sommes horizontales
	result.raw = _mm_hadd_ps(_mm_hadd_ps(mul0, mul1),
		_mm_hadd_ps(mul2, mul3));
	return (result);
}

// Alias pour compatibilité
t_tuple	matrice_to_tuple_simd(const t_mat4 *a, t_tuple tuple)
{
	return (matrice_to_tuple(a, tuple));
}