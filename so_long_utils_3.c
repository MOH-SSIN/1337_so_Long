#include "so_long.h"

void	print_image_3(t_carte *jeu, int i, int j, bool print)
{
	mlx_destroy_image(jeu->mlx, jeu->mlx_img); // Efface l'image précédente
	if (i == 1 && j == 0)
	    jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, JOUEUR_BOTTOM, &jeu->largeur_carte, &jeu->hauteur_carte);
	else if  (i == -1 && j == 0)
	{
	    jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, JOUEUR_TOP, &jeu->largeur_carte, &jeu->hauteur_carte);
	}
	else if  (i == 0 && j == 1)
	    jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, JOUEUR_RIGHT, &jeu->largeur_carte, &jeu->hauteur_carte);
	else if  (i == 0 && j == -1)
	    jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, JOUEUR_LEFT, &jeu->largeur_carte, &jeu->hauteur_carte);
	if (print)
	    mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, (jeu->pos_joueur_y  + j)* TAILLE, (jeu->pos_joueur_x + i) * TAILLE);
	else
	    mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, jeu->pos_joueur_y * TAILLE, jeu->pos_joueur_x  * TAILLE);
}

void print_door_out(t_carte *jeu)
{
	mlx_destroy_image(jeu->mlx, jeu->mlx_img);
	jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, DOOR_OPEN, &jeu->largeur_carte, &jeu->hauteur_carte);
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, jeu->pos_door_y * TAILLE, jeu->pos_door_x * TAILLE);
}

void print_image_2(t_carte *jeu, int i, int j)
{
    mlx_destroy_image(jeu->mlx, jeu->mlx_img); // Efface l'image précédente
    jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, ESPACE, &jeu->largeur_carte, &jeu->hauteur_carte);
    mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, jeu->pos_joueur_y * TAILLE, jeu->pos_joueur_x * TAILLE);
	print_image_3(jeu, i, j, true);
	jeu->pos_joueur_x += i;
	jeu->pos_joueur_y += j;
	if (!jeu->nbr_collect)
		print_door_out(jeu);
}

void	ft_move(t_carte **jeu, int i, int j)
{
	if ((*jeu)->carte[(*jeu)->pos_joueur_x + i][(*jeu)->pos_joueur_y + j] == '1' 
			|| ((*jeu)->carte[(*jeu)->pos_joueur_x + i][(*jeu)->pos_joueur_y + j] == 'E' && (*jeu)->nbr_collect))
	{
		print_image_3(*jeu, i, j, false);
		return ;// hade returne drtha hite fach kat print_image_3 5asni nkhroje bach print_image_2 mt5dmche onwli d5le f7ite hh
	}
	if ((*jeu)->carte[(*jeu)->pos_joueur_x + i][(*jeu)->pos_joueur_y + j] == '0'
		|| (*jeu)->carte[(*jeu)->pos_joueur_x + i][(*jeu)->pos_joueur_y + j] == 'C')
	{
		if ((*jeu)->carte[(*jeu)->pos_joueur_x + i][(*jeu)->pos_joueur_y + j] == 'C')
			(*jeu)->nbr_collect -= 1;
		(*jeu)->carte[(*jeu)->pos_joueur_x][(*jeu)->pos_joueur_y] = '0';
		(*jeu)->carte[(*jeu)->pos_joueur_x + i][(*jeu)->pos_joueur_y + j] = 'P';
	}
	if ((*jeu)->carte[(*jeu)->pos_joueur_x + i][(*jeu)->pos_joueur_y + j] == 'E' && !(*jeu)->nbr_collect)
	{
		ft_putstr_fd("You Win\n", 1);
		mlx_destroy_window((*jeu)->mlx, (*jeu)->mlx_win);//Fermer fenetre graphique cree par MiniLibX
		free_jeu(*jeu);
		exit(0);
	}
	print_image_2(*jeu, i, j);
}

int	ft_keymove(int click, t_carte **jeu)
{
	if (click == 126 || click == 13)//haut
		ft_move(jeu, -1, 0);// mi7ware i 4adi tn9se mais j 4atb9a fix
	else if (click == 125 || click == 1)// bas
		ft_move(jeu, 1, 0);// mi7ware i 4adi tzade mais j 4atb9a fix
	else if (click == 124 || click == 2)// droit
		ft_move(jeu, 0, 1);//mi7ware i fix tzade mais j 4atzade
	else if (click == 123 || click == 0)// gauche
		ft_move(jeu, 0, -1);//mi7ware i fix tzade mais j 4atn9se
	return (0);
}