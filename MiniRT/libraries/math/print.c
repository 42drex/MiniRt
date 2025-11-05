#include "mymath.h"

void	printfloat(float number, int enter)
{
	if (FLOAT_PRECISION == 0)
	{
		if (!enter)
			printf("%f", number);
		else
			printf("%f\n", number);
	}
	else if (FLOAT_PRECISION == 1)
	{
		if (!enter)
			printf("%lf", number);
		else
			printf("%lf\n", number);
	}
	else
		printf("T'as pas besoin de long double nous fait pas le mec precis\n");
}	

void	print_p_v_t(t_point *p, t_vector *v, t_tuple *t)
{
	if (p)
	{
		if (FLOAT_PRECISION == 0)
			printf("POINT= x->%f\ty->%f\tz->%f\n", p->x, p->y, p->z);
		if (FLOAT_PRECISION == 1)
			printf("POINT= x->%lf\ty->%lf\tz->%lf\n", p->x, p->y, p->z);
	}
	if (v)
	{
		if (FLOAT_PRECISION == 0)
			printf("VECTOR= x->%f\ty->%f\tz->%f\n", v->x, v->y, v->z);
		if (FLOAT_PRECISION == 1)
			printf("VECTOR= x->%lf\ty->%lf\tz->%lf\n", v->x, v->y, v->z);
	}
	if (t)
	{
		if (FLOAT_PRECISION == 0)
			printf("TUPLE= x->%f\ty->%f\tz->%f\tw->%f\n", t->x, t->y, t->z, t->w);
		if (FLOAT_PRECISION == 1)
			printf("TUPLE= x->%lf\ty->%lf\tz->%lf\tw->%lf\n", t->x, t->y, t->z, t->w);
	}
 }

void	print_matrice(const t_mat4 *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (j + 1 == 4)
				printfloat(a->a[i][j], 1);
			else
			{
				printfloat(a->a[i][j], 0);
				printf("\t");
			}
			j++;
		}
		i++;
	}
}

void	printAllmath(float x, float y)
{
	printf("Sin/Cos/Tan\n\n");
	printfloat(sin(x), 1);
	printfloat(cos(x), 1);
	printfloat(tan(x), 1);
	//printfloat(acos(2));
	printf("\natan/atan2\n\n");
	printfloat(atan(x), 1);
	printfloat(atan2(x, y), 1);
	printf("\nhyperbolic sine/hyperbolic cos/hyperboliaue tan\n\n");
	printfloat(sinh(x), 1);
	printfloat(cosh(x), 1);
	printfloat(tanh(x), 1);
	printf("\narc ayperbolic sine/arc hyperbolic cos\n\n");
	printfloat(asinh(x), 1);
	printfloat(acosh(x), 1);
	//printfloat(atanh(2));
	printf("\nexp/log/log10/pow/sqrt\n\n");
	printfloat(exp(x), 1);
	printfloat(log(x), 1);
	printfloat(log10(x), 1);
	printfloat(pow(x, y), 1);
	printfloat(sqrt(x), 1);
}
