#include "../windows.h"

t_point	ray_position(t_point point, t_tuple tuple, float time)
{
	return (new_point_forward(point, tuple_to_vector(prod_tuple(tuple, time))));
}
