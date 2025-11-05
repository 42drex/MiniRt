#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libraries/windows/windows.h"
# include "libraries/parsingRT/parsingrt.h"

int	init_all(t_win *win);
int	init_all_mutex(t_win *w);

# endif
