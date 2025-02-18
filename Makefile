# Définition des variables
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx
LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
SRCS = main.c
OBJ = $(SRCS:.c=.o)

# Règle par défaut (exécutable final)
all: $(NAME)

# Générer l'exécutable
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# Générer les fichiers objets à partir des sources
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@



# Nettoyer les fichiers objets
clean:
	rm -f $(OBJ)

# Nettoyer les fichiers objets et l'exécutable
fclean: clean
	rm -f $(NAME)

# Recompiler tout
re: fclean all
