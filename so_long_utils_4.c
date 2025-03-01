#include "so_long.h"


void print_door_out(t_carte *jeu)
{
	mlx_destroy_image(jeu->mlx, jeu->mlx_img);
	jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, DOOR_OPEN, &jeu->largeur_carte, &jeu->hauteur_carte);
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, jeu->pos_door_y * TAILLE, jeu->pos_door_x * TAILLE);
}

void    ft_print_movement(t_carte *jeu)
{
    jeu->nbr_mouve ++;
    printf("Mouvement : %d\n",jeu->nbr_mouve);
}