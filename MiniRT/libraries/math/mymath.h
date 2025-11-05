#ifndef MYMATH_H
# define MYMATH_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <float.h>
# include <immintrin.h> /* AVX / SSE intrinsics */
# include "../libft/libft.h"

# define EPSILON FLT_EPSILON

typedef struct s_sub
{
    int	x;
    int	y;
    int	size;
}	t_sub;

/* Default macro definitions */
# ifndef XSIZE
#  define XSIZE 4
# endif

# ifndef YSIZE
#  define YSIZE 4
# endif

# ifndef FLOAT_PRECISION
#  define FLOAT_PRECISION 0
# endif

typedef union __attribute__((aligned(16))) u_tuple
{
    struct
    {
        float	x;
        float	y;
        float	z;
        float	w;
    };
    float	data[4];
    __m128	raw;
}	t_tuple;

typedef union __attribute__((aligned(16))) u_point
{
    struct
    {
        float	x;
        float	y;
        float	z;
        float	w;
    };
    float	data[4];
    __m128	raw;
}	t_point;

typedef union __attribute__((aligned(16))) u_vector
{
    struct
    {
        float	x;
        float	y;
        float	z;
        float	w;
    };
    float	data[4];
    __m128	raw;
}	t_vector;

typedef struct s_shearing
{
    float x_y;
    float x_z;
    float y_x;
    float y_z;
    float z_x;
    float z_y;
}	t_shearing;

/* 4x4 matrix with SIMD-friendly layout:
   - .a for scalar access
   - .simd for 4 XMM rows (each __m128)
   - .ymm for using 2x __m256 if desired (optional usage)
   Aligned to 32 bytes for AVX loads/stores. */
typedef union u_mat4
{
    float		a[4][4];
    __m128		simd[4];
    __m256		ymm[2];
    struct
    {
        t_tuple	r1;
        t_tuple	r2;
        t_tuple	r3;
        t_tuple	r4;
    };
} __attribute__((aligned(32))) t_mat4;

/* ----- chaining transfo (matrices maintenant via t_mat4*) */
void		chaining(t_mat4 *newm, const t_mat4 *translation, \
            const t_mat4 *scaling, const t_mat4 *rotate);

/* ----- matrice utils */
void		mat4_set_row(t_mat4 *mat, int index, float a, float b, float c, float d);

/* ----- scaling */
void		scaling(t_mat4 *newm, float x, float y, float z);

/* ------ translation */
void		translation(t_mat4 *newm, float x, float y, float z);

/* ------ shearing */
void		shearing(t_mat4 *newm, t_shearing a);

/* ------ rotation */
float		radian(float deg);
void		rotate(t_mat4 *newm, float radian, char axe);
void		z_rotate(t_mat4 *newm, float radian);
void		y_rotate(t_mat4 *newm, float radian);
void		x_rotate(t_mat4 *newm, float radian);

/* ------ submatrix.c */
void		submatrix(t_mat4 *newm, const t_mat4 *a, t_sub sub);

/* ------ inverse.c */
float		determinant(const t_mat4 *a, int size);
float		cofactor(const t_mat4 *a, int x, int y, int size);
int		inverse(t_mat4 *newm, const t_mat4 *a);

/* ------ matrice.c */
int		isequal_EPS(float x, float y);
int		matrice_is_equal(const t_mat4 *a, const t_mat4 *b);
void		matrice_product(t_mat4 *newm, const t_mat4 *a, const t_mat4 *b);
void		matrice_product_simd(t_mat4 *newm, const t_mat4 *a, const t_mat4 *b);
void		matrice_product_avx(t_mat4 *newm, const t_mat4 *a, const t_mat4 *b);
void		asign_matrice(t_mat4 *tab, t_point pos, t_vector dir);

/* ------ convert_TPV */
t_vector	tuple_to_vector(t_tuple a);
t_point	tuple_to_point(t_tuple a);
t_tuple	tuple(void *tuple, int type);
t_tuple		**new_tuple_2tab(void);

/* ------ tuple_normalize */
float		mag_tuple(t_tuple tuple);
t_tuple		norm_tuple(t_tuple tuple);

/* ------ free */
void		free_tuple(t_tuple **tuple);

/* ------ Tupple_Operation */
t_tuple		prod_tuple(t_tuple a, float product);
t_tuple		neg_tupple(t_tuple a);
t_tuple		sub_tupple(t_tuple a, t_tuple b);
t_tuple		add_tupple(t_tuple a, t_tuple b);
t_tuple		matrice_to_tuple(const t_mat4 *a, t_tuple tuple);
t_tuple		matrice_to_tuple_simd(const t_mat4 *a, t_tuple tuple);

/* ------ Point_and_Vector */
t_point		new_point_forward(t_point point, t_vector vector);
t_point		new_point_backward(t_point point, t_vector vector);
t_vector	vector_from_points(t_point a, t_point b);
t_vector	substract_vector(t_vector a, t_vector b);

/* ------ vector.c */
float		magnitude(t_vector vector);
t_vector	normalize(t_vector vector);
float		dot_product(t_vector a, t_vector b);
t_vector	cross(t_vector a, t_vector b);
t_vector	neg_vector(t_vector a);

/* ------ Compare_Epsilon.c */
int		isequal_EPS(float x, float y);

/* ------ DEBUG */
void		printfloat(float number, int enter);
void		printAllmath(float x, float y);
void		print_p_v_t(t_point *p, t_vector *v, t_tuple *t);
void		print_matrice(const t_mat4 *a);

#endif