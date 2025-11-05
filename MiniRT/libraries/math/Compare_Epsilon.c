#include "mymath.h"

int	isequal_EPS(float x, float y)
{
	float	delta;

	delta = x - y;
	if (delta < 0.0f)
		delta = -delta;
	if (delta <= EPSILON)
		return (1);
	return (0);
}
