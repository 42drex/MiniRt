#include "windows.h"

unsigned int	gen_trgb(unsigned int opacity, unsigned int red,
			unsigned int green, unsigned int blue)
{
	if (opacity > 255 || red > 255 || green > 255 || blue > 255)
		return (0);
	return (opacity << 24 | red << 16 | green << 8 | blue);
}

unsigned int	get_opacity(unsigned int trgb)
{
	return ((trgb >> 24) & 0XFF);
}

unsigned int	get_r(unsigned int trgb)
{
	return ((trgb >> 16) & 0XFF);
}

unsigned int	get_g(unsigned int trgb)
{
	return ((trgb >> 8) & 0XFF);
}

unsigned int	get_b(unsigned int trgb)
{
	return (trgb & 0xFF);
}
