#ifndef WINDOWS_H
# define WINDOWS_H

# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "events.h"
# include "../thread/thread.h"
# include "../object/object.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"
# include "../math/mymath.h"

#ifndef XSIZE
# define XSIZE 1080

# endif

#ifndef YSIZE
# define YSIZE 720

# endif

# define FPS 60
# define SENSI 0.002
# define RESOLUTION 1

typedef struct s_colors
{
	unsigned int	red;
	unsigned int	blue;
	unsigned int	green;
	unsigned int	transparency;
	unsigned int	colors;
}	t_colors;

typedef struct s_overlay
{
	unsigned int	color;
	int		x_start;
	int		y_start;
	int		x_end;
	int		y_end;
}	t_overlay;

typedef struct s_move
{
	pthread_t	move;
	float	centerX;
	float	centerY;
	int		mouse;
	int		up;
	pthread_mutex_t	m_up;
	int		down;
	pthread_mutex_t	m_down;
	int		left;
	pthread_mutex_t	m_left;
	int		right;
	pthread_mutex_t	m_right;
}	t_move;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	t_scene		scene;
	pthread_mutex_t	m_pixel;
	int		close;
	pthread_mutex_t	m_close;
	t_move		move;
}	t_win;

// ---- move_camera

void	ft_move_press(int key, t_move *move);
void	ft_move_release(int key, t_move *move);

// ---- thread_move

void	*thread_movement(void *window);

// ----- show_or_hide_mouse

void	show_or_hide_mouse(t_win *win);

// ----- resolution

void	ft_resolution(int key, t_win *win);

// ----- mouse

int	mouse(int x, int y, t_win *win);

// ----- gen_img_from_cam

void		gen_img_from_cam(t_scene *scene);

// ----- move_camera
 
void		ft_move(int key, t_scene *s);

// ----- new_camera

void		new_camera(t_win *win, float fov, t_point pos, t_vector dir);

// ---------- Frame second

int		frame_per_second(void	*data);

// ---------- handle window

void		handle_events(t_win *win);

int		create_window(t_win *win, char *name);
int		free_windows(t_win *win);
void		create_fade(t_img *img, unsigned int top_color, unsigned int bottom_color);
void		create_overlay(t_overlay o, t_img *img);

// ----------- colors

unsigned int	gen_trgb(unsigned int opacity, unsigned int red,
			unsigned int green, unsigned int blue);
unsigned int	get_opacity(unsigned int trgb);
unsigned int	get_r(unsigned int trgb);
unsigned int	get_g(unsigned int trgb);
unsigned int	get_b(unsigned int trgb);
unsigned int	mix_colors(unsigned int a, unsigned int b, float alpha);
void		create_fade(t_img *img, unsigned int top_color, unsigned int bottom_color);
void		create_overlay(t_overlay o, t_img *img);

// ----------- debug/help

int	print_input_key(int key_pressed);

# endif
