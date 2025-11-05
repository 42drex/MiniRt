#include "object.h"

t_intersect	sphere_cross(t_point ray, t_vector direction, t_obj a)
{
	 t_intersect	cross = {0, {0.0f, 0.0f}};
 	 t_tuple	tmp;
 	 t_point	ro;
 	 t_vector	rd;
	 float		a_coef, b_coef, c_coef, disc, sd, t0, t1;
	 const float	eps = 1e-6f;

	 tmp = matrice_to_tuple(&a.inv, tuple(&ray, 1));
	 ro = tuple_to_point(tmp);
	 tmp = matrice_to_tuple(&a.inv, tuple(&direction, 0));
	 rd = tuple_to_vector(tmp);
	 t_vector s_to_p = vector_from_points(ro, (t_point){{0.0f, 0.0f, 0.0f, 1.0f}});
	 a_coef = dot_product(rd, rd);
	 if (fabsf(a_coef) < eps) return (cross);
	 b_coef = 2.0f * dot_product(rd, s_to_p);
	 c_coef = dot_product(s_to_p, s_to_p) - (a.radius * a.radius);
	 disc = b_coef * b_coef - 4.0f * a_coef * c_coef;
	 if (disc < eps) return (cross);
	 sd = sqrtf(disc);
	 t0 = (-b_coef - sd) / (2.0f * a_coef);
	 t1 = (-b_coef + sd) / (2.0f * a_coef);
	 if (t0 > t1) { float tmpf = t0; t0 = t1; t1 = tmpf; }
	 int hits = 0;
	 if (t0 > eps) cross.t[hits++] = t0;
	 if (t1 > eps) cross.t[hits++] = t1;
	 cross.touch = hits;
	 return (cross);
}
