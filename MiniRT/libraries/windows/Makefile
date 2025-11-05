# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shvalma <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 10:26:13 by shvalma           #+#    #+#              #
#    Updated: 2025/10/28 13:49:37 by shvalma          ###   ####lausanne.ch    #
#                                                                              #
# **************************************************************************** #

NAME = windows.a

SRCS =	fps.c		\
	create_window.c	\
	free_windows.c	\
	colors.c	\
	create_fade.c	\
	create_overlay.c	\
	handle_events.c	\
	print_input_key.c	\
	camera/new_camera.c	\
	camera/move_camera.c	\
	camera/thread_move.c	\
	camera/mouse.c		\
	camera/show_or_hide_mouse.c	\
	camera/resolution.c	\
	camera/gen_img_from_cam.c

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -DXSIZE=$(XSIZE) -DYSIZE=$(YSIZE)

AR = ar rc
RM = rm -rf

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
