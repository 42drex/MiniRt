NAME = miniRT

LIBFT_DIR = ./libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./libraries/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MATH_DIR = ./libraries/math
MATH = $(MATH_DIR)/math.a
WINDOWS_DIR = ./libraries/windows
WINDOWS = $(WINDOWS_DIR)/windows.a
OBJECT_DIR = ./libraries/object
OBJECT = $(OBJECT_DIR)/object.a
THREAD_DIR = ./libraries/thread
THREAD = $(THREAD_DIR)/thread.a
PARSINGRT_DIR = ./libraries/parsingRT
PARSINGRT = $(PARSINGRT_DIR)/parsing_rt.a
ERROR_DIR = ./libraries/error
ERROR = $(ERROR_DIR)/error.a

LIBRARY = $(WINDOWS) $(OBJECT) $(PARSINGRT) $(THREAD) $(ERROR) $(MATH) $(LIBFT) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

VALGRIND = @valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

LIBC = ar rcs
CC = cc
RM = rm -f

XSIZE ?= 1280
YSIZE ?= 720

FLAGS = -Wall -Wextra -Werror -Iinc -g3 -O3 -msse2 -msse4.1 -msse3 -mavx -DXSIZE=$(XSIZE) -DYSIZE=$(YSIZE)

SRCS = camera.c init_all.c init_all_mutex.c

OBJ_DIR = obj
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))

vpath %c

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

all :	$(NAME)

$(NAME) : ${OBJS} ${OBJECT} ${THREAD} ${PARSINGRT} ${ERROR} ${MATH} ${WINDOWS} ${LIBFT} ${MLX}
	@echo "Building MiniRT.."
	@${CC} ${OBJS} $(FLAGS) $(LIBRARY) -o ${NAME}
	@echo "MiniRT is ready !"

valgrind: $(NAME)
	@echo "Running $(NAME) with Valgrind..."
	$(VALGRIND) ./$(NAME)

$(ERROR) :
	@echo "Building error..."
	@make --no-print-directory -C $(ERROR_DIR)

$(PARSINGRT) :
	@echo "Building parsingRT..."
	@make --no-print-directory -C $(PARSINGRT_DIR)

$(OBJECT) :
	@echo "Building object..."
	@make --no-print-directory -C $(OBJECT_DIR)

$(WINDOWS) :
	@echo "Building windows..."
	@make --no-print-directory -C $(WINDOWS_DIR)

$(THREAD) :
	@echo "Building thread..."
	@make --no-print-directory -C $(THREAD_DIR)

$(MATH) :
	@echo "Building math..."
	@make --no-print-directory -C $(MATH_DIR)

$(MLX) :
	@echo "Building mlx..."
	@make --no-print-directory -C $(MLX_DIR)

$(LIBFT) :
	@echo "Building libft..."
	@make --no-print-directory -C $(LIBFT_DIR)

clean:
	@echo "Cleaning..."
	@rm -rf $(OBJ_DIR)
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@make --no-print-directory -C $(MLX_DIR) clean
	@make --no-print-directory -C $(WINDOWS_DIR) clean
	@make --no-print-directory -C $(MATH_DIR) clean
	@make --no-print-directory -C $(OBJECT_DIR) clean
	@make --no-print-directory -C $(THREAD_DIR) clean
	@make --no-print-directory -C $(PARSINGRT_DIR) clean
	@make --no-print-directory -C $(ERROR_DIR) clean

fclean: clean
	@echo "Cleaning all..."
	@rm -f $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	@make --no-print-directory -C $(MLX_DIR) clean
	@make --no-print-directory -C $(WINDOWS_DIR) fclean
	@make --no-print-directory -C $(MATH_DIR) fclean
	@make --no-print-directory -C $(OBJECT_DIR) fclean
	@make --no-print-directory -C $(THREAD_DIR) fclean
	@make --no-print-directory -C $(PARSINGRT_DIR) fclean
	@make --no-print-directory -C $(ERROR_DIR) fclean

re:         fclean all

.PHONY : all clean fclean re
