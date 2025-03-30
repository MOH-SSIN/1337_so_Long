# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 15:10:12 by mez-zahi          #+#    #+#              #
#    Updated: 2025/03/30 12:58:35 by mez-zahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus

SRC_FILE = src/so_long.c src/get_next_line.c src/get_next_line_utlis.c \
            src/verification_map.c src/init_jeu.c src/init_carte.c \
            src/free_stack.c src/so_long_utils_1.c src/so_long_utils_2.c \
            src/so_long_utils_3.c src/so_long_utils_4.c src/so_long_utils_5.c \
			src/verification_map_utils.c \

BONUS_SRC_FILE = bonus/so_long_bonus.c bonus/get_next_line_bonus.c  \
				 bonus/get_next_line_utlis_bonus.c \
                 bonus/verification_map_bonus.c bonus/init_jeu_bonus.c \
                 bonus/init_carte_bonus.c bonus/free_stack_bonus.c \
                 bonus/so_long_utils_1_bonus.c bonus/so_long_utils_2_bonus.c \
                 bonus/so_long_utils_3_bonus.c bonus/so_long_utils_4_bonus.c \
                 bonus/so_long_utils_5_bonus.c \
				 bonus/verification_map_utils_bonus.c \

OBJ_FILE = $(SRC_FILE:.c=.o)
BONUS_OBJ_FILE = $(BONUS_SRC_FILE:.c=.o)

HEADER = src/so_long.h bonus/so_long_bonus.h
BONUS_HEADER =  bonus/so_long_bonus.h 

CC = cc
RM = rm -rf
CFLAGS = -I$(MLX_DIR) -Ilibft -Ig_n_l

MLX_DIR = ./minilibx_mms_20200219
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all : $(NAME)

bonus : $(BONUS_NAME)

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ_FILE) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_FILE) $(LIBFT) -o $(NAME) $(MLX_FLAGS)

$(BONUS_NAME) : $(BONUS_OBJ_FILE) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJ_FILE) $(LIBFT) -o $(BONUS_NAME) $(MLX_FLAGS)

$(LIBFT): $(LIBFT_DIR)/*.c
	$(MAKE) -C $(LIBFT_DIR)

clean :
	$(RM) $(OBJ_FILE) $(BONUS_OBJ_FILE)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(NAME) $(BONUS_NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re : fclean all
