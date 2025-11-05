#include "object.h"

static inline float	clamp01(float value)
{
	if (value < 0.0f)
		return (0.0f);
	if (value > 1.0f)
		return (1.0f);
	return (value);
}

static inline t_tuple	color_to_tuple(unsigned int color)
{
	t_tuple	result;

	result.x = ((color >> 16) & 0xFF) / 255.0f;
	result.y = ((color >> 8) & 0xFF) / 255.0f;
	result.z = (color & 0xFF) / 255.0f;
	result.w = 0.0f;
	return (result);
}

static inline t_tuple	mul_components(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = a.x * b.x;
	result.y = a.y * b.y;
	result.z = a.z * b.z;
	result.w = 0.0f;
	return (result);
}

static inline unsigned int	tuple_to_color(t_tuple color)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	red = (unsigned int)(clamp01(color.x) * 255.0f + 0.5f);
	green = (unsigned int)(clamp01(color.y) * 255.0f + 0.5f);
	blue = (unsigned int)(clamp01(color.z) * 255.0f + 0.5f);
	if (red > 255)
		red = 255;
	if (green > 255)
		green = 255;
	if (blue > 255)
		blue = 255;
	return ((0 << 24) | (red << 16) | (green << 8) | blue);
}

static inline float	clamp_ratio(float ratio)
{
	if (ratio < 0.0f)
		return (0.0f);
	if (ratio > 1.0f)
		return (1.0f);
	return (ratio);
}

unsigned int	shade_color(const t_scene *scene, const t_hit *hit)
{
	t_tuple	object_color;
	t_tuple	result;
	t_tuple	ambient_color;
	t_tuple	diffuse_color;
	int	i;

	if (!scene || !hit || !hit->found || !hit->object)
		return (0x00FFFFFF);
	object_color = color_to_tuple(hit->object->color);
	result = (t_tuple){{0.0f, 0.0f, 0.0f, 0.0f}};
	ambient_color = color_to_tuple(scene->alight.color);
	ambient_color = mul_components(object_color, ambient_color);
	ambient_color = prod_tuple(ambient_color, clamp_ratio(scene->alight.ratio));
	result = add_tupple(result, ambient_color);
	i = 0;
	while (scene->light && i < scene->num_light)
	{
		t_vector	to_light;
		t_vector	light_dir;
		float		ndotl;
		float		intensity;

		to_light = vector_from_points(scene->light[i].pos, hit->point);
		light_dir = normalize(to_light);
		ndotl = dot_product(hit->normal, light_dir);
		if (ndotl > 0.0f)
		{
			diffuse_color = color_to_tuple(scene->light[i].color);
			diffuse_color = mul_components(object_color, diffuse_color);
			intensity = clamp_ratio(scene->light[i].ratio) * ndotl;
			diffuse_color = prod_tuple(diffuse_color, intensity);
			result = add_tupple(result, diffuse_color);
		}
		i++;
	}
	return (tuple_to_color(result));
}
