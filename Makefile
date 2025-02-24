NAME = so_long

SRC_FILE = so_long.c  g_n_l/get_next_line.c g_n_l/get_next_line_utlis.c \
			verification_map.c \
			init_jeu.c init_carte.c\
			free_stack.c \
			so_long_utils_1.c\
			so_long_utils_2.c\

OBJ_FILE = $(SRC_FILE:.c=.o)

HEADER = so_long.h g_n_l/get_next_line.h
CC = cc
RM = rm -rf
CFLAGS = -I$(MLX_DIR) -Ilibft -Ig_n_l

MLX_DIR = ./minilibx_opengl_20191021
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all : $(NAME)

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ_FILE) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_FILE) $(LIBFT) -o $(NAME) $(MLX_FLAGS)

$(LIBFT): $(LIBFT_DIR)/*.c
	$(MAKE) -C $(LIBFT_DIR)

clean :
	$(RM) $(OBJ_FILE)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re : fclean all