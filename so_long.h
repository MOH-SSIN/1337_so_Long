#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "../g_n_l/get_next_line.h"
#include <stdbool.h>
#include <fcntl.h>
#include "mlx.h"
#include "stdio.h"

# define TAILLE 60
# define ESPACE "assets/baground.xpm"//0
// # define ESPACE_2 "image/baground.xpm"//0
# define COLLECT "image/Collect.xpm"//C
# define DOOR "image/Close_Door.xpm"//E
# define DOOR_OPEN "image/Open_Door.xpm"//E
# define JOUEUR_BOTTOM "image/Pac-Man_down.xpm"
# define JOUEUR_TOP "image/Pac-Man_up.xpm"//P
# define JOUEUR_RIGHT "image/Pac-Man_right.xpm"//P
# define JOUEUR_LEFT "image/Pac-Man_left.xpm"//P
# define MUR "image/wall.xpm"//1
// # define ENNEMI ""//

typedef struct s_carte
{
    void    *mlx;
    void    *mlx_win;
    void    *mlx_img;
    char    **carte;
    int     nbr_collect;
    int     largeur_carte;
    int     hauteur_carte;
    int     pos_joueur_x;
    int     pos_joueur_y;
    int     pos_ennemi_x;
    int     pos_ennemi_y;
    bool    partie_terminee;
    int     pos_door_x;
    int     pos_door_y;
    int     nbr_mouve;
} t_carte;

// init_carte.c
char    **charger_carte(char *av[], t_carte **jeu);


//free_stack.c
void    free_jeu(t_carte *jeu);
void    free_map(char **map);
void	free_copy_map(char **copie, int j);
// Fonctions de gestion du jeu
bool    initialiser_jeu(t_carte **jeu);

int verfication(t_carte *jeu);

//initalisation de jeu
int init_jeu(t_carte **jeu);

// so_long_utlis_1.c
int ft_exit(t_carte **jeu);
int ft_keymove(int click, t_carte **jeu);
char **copie_map(char **carte);
void ft_marque(char **carte, int i, int j);

// so_long_utlis_2.c
int aid_verif_elements(char element,int *p, int *e, int *c);
int get_position_player(char **copie, int *i, int *j);
int ft_presence_elemntes(char **copie);
// void print_images(t_carte *jeu);
#endif
