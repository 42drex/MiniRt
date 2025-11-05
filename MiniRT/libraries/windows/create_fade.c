#include "windows.h"

void	create_fade(t_img *img, unsigned int top_color, unsigned int bottom_color)
{
	t_colors	color;
	int		x;
	int		y;
	float		ratio;
	char		*pixel;

	y = -1;
	while (++y < YSIZE)
	{
		ratio = (float)y / (YSIZE - 1);
		color.red = get_r(top_color) * (1 - ratio) + get_r(bottom_color) * ratio;
		color.green = get_g(top_color) * (1 - ratio) + get_g(bottom_color) * ratio;
		color.blue = get_b(top_color) * (1 - ratio) + get_b(bottom_color) * ratio;
		color.colors = gen_trgb(0, color.red, color.green, color.blue);
		x = -1;
		while (++x < XSIZE)
		{
			pixel = img->data + (y * img->size_line + x * (img->bpp / 8));
			*(unsigned int *)pixel = color.colors;
		}
	}
}

