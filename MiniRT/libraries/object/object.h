#ifndef OBJECT_H
# define OBJECT_H

# include "../math/mymath.h"
# include "../thread/thread.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

typedef enum s_type
{
	SPHERE,
	CUBE,
	CYLINDRE,
	PLAN
}	t_type;

typedef struct s_intersect
{
	float	touch;
	float	t[2];
}	t_intersect;

typedef struct s_obj
{
	t_type		type;
	t_point		origin;
	t_vector	dir;
	float	radius;
	float	height;
	unsigned int	color;
	t_mat4	scaling;
	t_mat4	shearing;
	t_mat4	translation;
	t_mat4	inv;
	t_mat4	inv_t;
	t_mat4	rotation;
	t_mat4	chaining;
}	t_obj;

typedef struct s_hit
{
    int			found;
    float		t;
    t_point		point;
    t_vector	normal;
    t_obj		*object;
}	t_hit;

typedef struct s_cam
{
	t_point		pos;
	t_vector	norm_dir;
	float	fov;
	float	aspect;
	float	halfX;
	float	halfY;
	t_mat4	matrice;
	pthread_mutex_t	m_cam;
}	t_cam;

typedef struct s_light
{
	float	ratio;
	unsigned int	color;
	t_point		pos;
}	t_light;

typedef struct s_alight
{
	float	ratio;
	unsigned int	color;
}	t_alight;

typedef struct s_scene
{
	t_cam		cam;
	t_obj		*object;
	int		num_obj;
	t_alight	alight;
	t_light		*light;
	int		num_light;
	t_img		*img;
	pthread_mutex_t	m_pixel;
	int		resolution;
	t_intersect	cross;
}	t_scene;

// ----- sphere_geometry

t_intersect	sphere_cross(t_point ray, t_vector direction, t_obj a);

// ----- new_sphere

void	trace_nearest(const t_scene *scene, const t_point origin,
            const t_vector dir, t_hit *hit);
unsigned int	shade_color(const t_scene *scene, const t_hit *hit);
t_obj	new_sphere(t_point origin, float radius);

#endif
