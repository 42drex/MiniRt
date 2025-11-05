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

NAME = math.a

XSIZE ?= 4
YSIZE ?= 4

SRCS = print.c Compare_Epsilon.c	\
		TuplePointVector/convert_TPV.c	\
		TuplePointVector/Point_and_Vector.c	\
		TuplePointVector/vector.c	\
		TuplePointVector/tuple_operation.c	\
		TuplePointVector/tuple_normalize.c	\
		TuplePointVector/free_tuple.c	\
       		matrice/matrice.c	\
		matrice/matrice_simd.c	\
		matrice/matrice_row.c	\
		matrice/submatrix.c	\
		matrice/inverse.c	\
		matrice/rotation.c	\
		matrice/translation.c	\
		matrice/scaling.c	\
		matrice/shearing.c

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -msse2 -msse4.1 -msse3 -mavx -DXSIZE=$(XSIZE) -DYSIZE=$(YSIZE)
LDFLAGS = -lm

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
