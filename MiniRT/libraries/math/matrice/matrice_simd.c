#include "../mymath.h"
#include <immintrin.h>  // Pour AVX

/* Version AVX (256-bit) du produit matriciel
 * Inspirée de "lag" - traite 2 lignes simultanément
 * Nécessite AVX (-mavx dans les flags de compilation) */

static inline void	matrix_mul_stage1(const t_mat4 *a, const t_mat4 *b,
	__m256 *c)
{
	__m256	broadcast[2];
	__m256	b_cols;

	// Broadcast a[0].x et a[1].x sur tout le registre 256-bit
	broadcast[0] = _mm256_shuffle_ps(a->ymm[0], a->ymm[0],
		_MM_SHUFFLE(0, 0, 0, 0));
	broadcast[1] = _mm256_shuffle_ps(a->ymm[1], a->ymm[1],
		_MM_SHUFFLE(0, 0, 0, 0));
	
	// Prend la première ligne de B et duplique sur 256-bit
	b_cols = _mm256_broadcast_ps((__m128 *)&b->simd[0]);
	
	// Multiplie : a[i].x * b.ligne0
	c[0] = _mm256_mul_ps(broadcast[0], b_cols);
	c[1] = _mm256_mul_ps(broadcast[1], b_cols);
	
	// Broadcast a[0].y et a[1].y
	broadcast[0] = _mm256_shuffle_ps(a->ymm[0], a->ymm[0],
		_MM_SHUFFLE(1, 1, 1, 1));
	broadcast[1] = _mm256_shuffle_ps(a->ymm[1], a->ymm[1],
		_MM_SHUFFLE(1, 1, 1, 1));
	
	// Prend la deuxième ligne de B
	b_cols = _mm256_broadcast_ps((__m128 *)&b->simd[1]);
	
	// Multiplie et accumule : += a[i].y * b.ligne1
	c[0] = _mm256_add_ps(c[0], _mm256_mul_ps(broadcast[0], b_cols));
	c[1] = _mm256_add_ps(c[1], _mm256_mul_ps(broadcast[1], b_cols));
}

static inline void	matrix_mul_stage2(const t_mat4 *a, const t_mat4 *b,
	__m256 *c)
{
	__m256	broadcast[2];
	__m256	b_cols;

	// Broadcast a[0].z et a[1].z
	broadcast[0] = _mm256_shuffle_ps(a->ymm[0], a->ymm[0],
		_MM_SHUFFLE(2, 2, 2, 2));
	broadcast[1] = _mm256_shuffle_ps(a->ymm[1], a->ymm[1],
		_MM_SHUFFLE(2, 2, 2, 2));
	
	// Prend la troisième ligne de B
	b_cols = _mm256_broadcast_ps((__m128 *)&b->simd[2]);
	
	// Multiplie et accumule : += a[i].z * b.ligne2
	c[0] = _mm256_add_ps(c[0], _mm256_mul_ps(broadcast[0], b_cols));
	c[1] = _mm256_add_ps(c[1], _mm256_mul_ps(broadcast[1], b_cols));
	
	// Broadcast a[0].w et a[1].w
	broadcast[0] = _mm256_shuffle_ps(a->ymm[0], a->ymm[0],
		_MM_SHUFFLE(3, 3, 3, 3));
	broadcast[1] = _mm256_shuffle_ps(a->ymm[1], a->ymm[1],
		_MM_SHUFFLE(3, 3, 3, 3));
	
	// Prend la quatrième ligne de B
	b_cols = _mm256_broadcast_ps((__m128 *)&b->simd[3]);
	
	// Multiplie et accumule : += a[i].w * b.ligne3
	c[0] = _mm256_add_ps(c[0], _mm256_mul_ps(broadcast[0], b_cols));
	c[1] = _mm256_add_ps(c[1], _mm256_mul_ps(broadcast[1], b_cols));
}

void	matrice_product_avx(t_mat4 *out, const t_mat4 *a, const t_mat4 *b)
{
	__m256	result[2];

	matrix_mul_stage1(a, b, result);
	matrix_mul_stage2(a, b, result);
	
	// Stocke les 2 lignes résultantes (256-bit = 2 lignes de 128-bit)
	out->ymm[0] = result[0];
	out->ymm[1] = result[1];
}

