#include "../windows.h"

static t_tuple	new_cam_tuple(int i, int j, float halfX, float halfY)
{
	t_tuple		new;	

	new.x = (((2 * (i + 0.5)) / XSIZE) - 1) * halfX;
	new.y =  (1 - ((2 * (j + 0.5)) / YSIZE)) * halfY;
	new.z = 1;
	new.w = 0;
	return (new);
}

static unsigned int	find_color(const t_scene *scene, const t_hit *hit)
{
    if (!hit->found)
        return (gen_trgb(0, 0, 0, 0	));
    return (shade_color(scene, hit));
}

static unsigned int	ray_to_pixel(t_scene *scene, int x, int y)
{
    t_hit		hit;
    t_tuple		ray;

    pthread_mutex_lock(&scene->cam.m_cam);
    ray = norm_tuple(matrice_to_tuple(&scene->cam.matrice,
            new_cam_tuple(x, y, scene->cam.halfX, scene->cam.halfY)));
    pthread_mutex_unlock(&scene->cam.m_cam);
    trace_nearest(scene, scene->cam.pos, tuple_to_vector(ray), &hit);
    return (find_color(scene, &hit));
}

static void	draw_square(const t_scene *scene, unsigned int color,
        int currentX, int currentY)
{
    const int	bytes_per_pixel = scene->img->bpp >> 3;
    const int	stride = scene->img->size_line;
    const int	max_rows = scene->resolution;
    const int	max_cols = scene->resolution;
    const int	rows = ((currentY + max_rows) <= YSIZE) ? max_rows : (YSIZE - currentY);
    const int	cols = ((currentX + max_cols) <= XSIZE) ? max_cols : (XSIZE - currentX);
    char		*row;
    int		y;
    int		x;

    if (rows <= 0 || cols <= 0)
        return ;
    row = scene->img->data + currentY * stride + currentX * bytes_per_pixel;
    y = 0;
    while (y < rows)
    {
        unsigned int	*pixels = (unsigned int *)row;

        x = 0;
        while (x < cols)
        {
            pixels[x] = color;
            x++;
        }
        row += stride;
        y++;
    }
}
			
void	gen_img_from_cam(t_scene *scene)
{
	int	x;
	int	y;

	if (!scene || !scene->img)
		return ;
	pthread_mutex_lock(&scene->m_pixel);
	y = 0;
	while (y < YSIZE)
	{
		x = 0;
		while (x < XSIZE)
		{
			draw_square(scene, ray_to_pixel(scene, x, y), x, y);
			x += scene->resolution;
		}
		y += scene->resolution;
	}
	pthread_mutex_unlock(&scene->m_pixel);
}
