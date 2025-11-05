#ifndef PARSINGRT_H
# define PARSINGRT_H

# include "../libft/libft.h"
# include "../error/error.h"
# include "../windows/windows.h"
# include "../object/object.h"


int	asign_object_to_scene(char *line, t_scene *s);

// ---- realloc

t_obj	*realloc_obj(t_obj *old, int number);
t_light *realloc_light(t_light *old, int number);

// ---- put_object

t_obj	*put_object(char **object, t_obj *o, int type, int *number);

// ---- put_cam

int	put_cam(char **object, t_cam *c);

// ---- put_alight

int	put_alight(char **object, t_alight *al);

// ---- put_light 

t_light	*put_light(char **object, t_light *l, int *number);

// ---- new_color_from_rt

int	new_color_from_rt(unsigned int *color, char *object);

// ---- new_normvector_from_rt

int	new_normvector_from_rt(t_vector *dir, char *line);

// ---- new_point_from_rt

int	new_point_from_rt(t_point *pos, char *line);

// ---- remove_underline

void	remove_char(char **object, char supp);

// ---- check_object.c

int	check_object(char **object);

// ----- parsing.c

int	ft_scene_valid(t_scene *s, char *scene);

// ----- ft_atof

int	ft_atof(float *number, char *str);

#endif
