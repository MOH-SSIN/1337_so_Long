#include "so_long_bonus.h"


void print_door_out(t_carte *jeu)
{
	mlx_destroy_image(jeu->mlx, jeu->mlx_img);
	jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, DOOR_OPEN, &jeu->largeur_carte, &jeu->hauteur_carte);
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, jeu->pos_door_y * TAILLE, jeu->pos_door_x * TAILLE);
}

void	position_enimi(t_carte **jeu)
{
	int	i;
	int	j;

    i = 0;
    while ((*jeu)->carte[i])
    {
        j = 0;
        while ((*jeu)->carte[i][j])
        {
            if ((*jeu)->carte[i][j] == 'X')
			{
				(*jeu)->pos_ennemi_x = i;
				(*jeu)->pos_ennemi_y = j;
				return ;
			}
            (j)++;
        }
        (i)++;
    }
}

void	position_player(t_carte **jeu)
{
	int	i;
	int	j;

    i = 0;
    while ((*jeu)->carte[i])
    {
        j = 0;
        while ((*jeu)->carte[i][j])
        {
            if ((*jeu)->carte[i][j] == 'P')
			{
				(*jeu)->pos_joueur_x = i;
				(*jeu)->pos_joueur_y = j;
				return ;
			}
            (j)++;
        }
        (i)++;
    }
}