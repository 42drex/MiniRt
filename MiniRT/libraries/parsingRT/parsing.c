#include "parsingrt.h"

int	ft_scene_valid(t_scene *s, char *scene)
{
	int		fd;
	char		*line;

	if (ft_strncmp(&scene[ft_strlen(scene) - 3], ".rt", 4))
		return (printf("La map n'est pas en format .rt\n"), 1);
	fd = open(scene, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (asign_object_to_scene(line, s))
			fd = -1;
		free(line);
	}
	if (fd == -1)
		return (1);
	return (0);
}

/*int	main(int argc, char **argv)
{
	(void)argc;

	t_scene s;
	ft_scene_valid(&s, argv[1]);
	return (0);
}*/
