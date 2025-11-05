#include "windows.h"

unsigned int	mix_colors(unsigned int a, unsigned int b, float alpha)
{
	t_colors	new;
	
	new.red = get_r(a) * (1 - alpha) + get_r(b) * alpha;
	new.green = get_g(a) * (1 - alpha) + get_g(b) * alpha;
	new.blue = get_b(a) * (1 - alpha) + get_b(b) * alpha;
	return (gen_trgb(0, new.red, new.green, new.blue));
}

void	create_overlay(t_overlay o, t_img *img)
{
	float		alpha;
	int		x;
	char		*pixel;

	alpha = (255 - get_opacity(o.color)) / 255.0;
	while (o.y_start <= o.y_end)
	{
		x = o.x_start;
		while (x <= o.x_end)
		{
			pixel = img->data + (o.y_start * img->size_line + x * (img->bpp / 8));
			*(unsigned int *)pixel = mix_colors(o.color, *(unsigned int *)pixel, alpha);
			x++;
		}
		o.y_start++;
	}
}
