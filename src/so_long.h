#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include "../g_n_l/get_next_line.h"
#include <stdbool.h>
#include <fcntl.h>
#include "mlx.h"
#include "stdio.h"

# define TAILLE 50
# define ESPACE "image_1/baground.xpm"
# define COLLECT "image_1/Collect.xpm"//C
# define DOOR "image_1/door_close.xpm"//E
# define DOOR_OPEN "image_1/door_open.xpm"//E
# define JOUEUR_BOTTOM "image_1/pac_man_botom.xpm"
# define JOUEUR_TOP "image_1/pac_man_top.xpm"//P
# define JOUEUR_RIGHT "image_1/pac_man_right.xpm"//P
# define JOUEUR_LEFT "image_1/pac_man_left.xpm"//P
# define MUR "image_1/wall.xpm"//1
# define MUR_2 "image_1/wall.xpm"//1
# define ENNEMI "image_1/Enemy.xpm"//

// 
static int direction = 1;// hadi bach ncontroler movment dyale enimi dans direction x-> i
static int frame_count = 0;// hadi drtha bach ncoteoler c=vitese dyale enimi

typedef struct s_carte
{
    int     direction;
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

//so_long_utils_4.c
void print_door_out(t_carte *jeu);
void    ft_print_movement(t_carte *jeu);

//so_long_utils_5.c
void	player_win(t_carte **jeu);
void	enimi_win(t_carte **jeu);
void	ft_sortie(t_carte **jeu);

//
void ft_chek_null(t_carte *jeu);
#endif
