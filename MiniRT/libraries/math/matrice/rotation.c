#include "../mymath.h"

float	radian(float deg)
{
	float	rad;

	rad = (deg / 180.0f) * (float)M_PI;
	return (rad);
}

void	z_rotate(t_mat4 *newm, float angle)
{
	float	c;
	float	s;

	c = cosf(angle);
	s = sinf(angle);
	mat4_set_row(newm, 0, c, -s, 0.0f, 0.0f);
	mat4_set_row(newm, 1, s, c, 0.0f, 0.0f);
	mat4_set_row(newm, 2, 0.0f, 0.0f, 1.0f, 0.0f);
	mat4_set_row(newm, 3, 0.0f, 0.0f, 0.0f, 1.0f);
}

void	y_rotate(t_mat4 *newm, float angle)
{
	float	c;
	float	s;

	c = cosf(angle);
	s = sinf(angle);
	mat4_set_row(newm, 0, c, 0.0f, s, 0.0f);
	mat4_set_row(newm, 1, 0.0f, 1.0f, 0.0f, 0.0f);
	mat4_set_row(newm, 2, -s, 0.0f, c, 0.0f);
	mat4_set_row(newm, 3, 0.0f, 0.0f, 0.0f, 1.0f);
}

void	x_rotate(t_mat4 *newm, float angle)
{
	float	c;
	float	s;

	c = cosf(angle);
	s = sinf(angle);
	mat4_set_row(newm, 0, 1.0f, 0.0f, 0.0f, 0.0f);
	mat4_set_row(newm, 1, 0.0f, c, -s, 0.0f);
	mat4_set_row(newm, 2, 0.0f, s, c, 0.0f);
	mat4_set_row(newm, 3, 0.0f, 0.0f, 0.0f, 1.0f);
}

void	rotate(t_mat4 *newm, float angle, char axe)
{
	if (axe == 'x')
		x_rotate(newm, angle);
	if (axe == 'y')
		y_rotate(newm, angle);
	if (axe == 'z')
		z_rotate(newm, angle);
}
