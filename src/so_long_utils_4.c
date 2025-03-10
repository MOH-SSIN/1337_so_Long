#include "so_long.h"


void print_door_out(t_carte *jeu)
{
	mlx_destroy_image(jeu->mlx, jeu->mlx_img);
	jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, DOOR_OPEN, &jeu->largeur_carte, &jeu->hauteur_carte);
	if(!jeu->mlx_img)
	{
		free_jeu(jeu);
		ft_putstr_fd("overture image door echoue\n",1);
		exit(1);
	}
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, jeu->pos_door_y * TAILLE, jeu->pos_door_x * TAILLE);
}

void    ft_print_movement(t_carte *jeu)
{
    jeu->nbr_mouve ++;
    // printf("Mouvement : %d\n",jeu->nbr_mouve);
	char *str;
	str = ft_itoa(jeu->nbr_mouve);
	if(!str)
	{
		free_jeu(jeu);
		exit(1);
	}
	write(1,"MV:",1);
	write(1,str,ft_strlen(str));
	write(1,"\n",1);
}
