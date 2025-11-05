#include "libraries/parsingRT/parsingrt.h"
#include "libraries/windows/windows.h"
#include "minirt.h"
#include <pthread.h>

int	main(int argc, char **argv)
{
	t_win	win;

	if (argc != 2)
		return (1);
	if (init_all(&win))
		return (1);
	if (ft_scene_valid(&win.scene, argv[1]))
		return (1);	
	if (create_window(&win, "miniRT"))
		return (1);
	gen_img_from_cam(&win.scene);
	pthread_create(&win.move.move, NULL, thread_movement, &win);
	handle_events(&win);
	pthread_join(win.move.move, NULL);
	return (0);
}
