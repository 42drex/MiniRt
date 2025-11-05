# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shvalma <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 10:26:13 by shvalma           #+#    #+#              #
#    Updated: 2025/10/14 14:30:58 by shvalma          ###   ####lausanne.ch    #
#                                                                              #
# **************************************************************************** #

NAME = parsing_rt.a

SRCS = parsing.c ft_atof.c new_normvector_from_rt.c put_alight.c put_object.c	\
	asign_object_to_scene.c new_point_from_rt.c put_cam.c remove_underline.c	\
	check_object.c new_color_from_rt.c put_light.c realloc.c


OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror

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
