#include "so_long_bonus.h"

void update_move_count(t_carte *jeu)
{
	char *count_str;
	char *string_put;

	count_str = ft_itoa(jeu->nbr_mouve);
	if (!count_str)
		return ;
	string_put = ft_strjoin("MV:", count_str);
	free(count_str);
	if (!string_put)
		return ;
	if (jeu->mlx_img)
	mlx_destroy_image(jeu->mlx, jeu->mlx_img);
	jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, MUR_2, &jeu->largeur_carte, &jeu->hauteur_carte);
	//faire une chek
	ft_chek_null(jeu);
	if (!jeu->mlx_img)
	{
		free(string_put);
		return ;
	}
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, 0, 0);
	// atention : hna i9dre iknone leaks !!
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, 1 * TAILLE,  0);// hna x howa mi7ware x et y howa mi7ware y mais les cas lo khrine la dan votr code 
	mlx_string_put(jeu->mlx, jeu->mlx_win, 0, 0, 0xFFFFFF, string_put);// 3ndi 3ibe hna !! fach knfote 1000 l7ale baniya ndire chi image tama li width dyalha kbire xwiya !!
	free(string_put);
}

void	print_image_3(t_carte *jeu, int i, int j, bool print)
{
	mlx_destroy_image(jeu->mlx, jeu->mlx_img); //knsuprimer image li precedente
	if (i == 1 && j == 0)
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, JOUEUR_BOTTOM, &jeu->largeur_carte, &jeu->hauteur_carte);
		ft_chek_null(jeu);
	}
	else if  (i == -1 && j == 0)
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, JOUEUR_TOP, &jeu->largeur_carte, &jeu->hauteur_carte);
		ft_chek_null(jeu);
	}
	else if  (i == 0 && j == 1)
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, JOUEUR_RIGHT, &jeu->largeur_carte, &jeu->hauteur_carte);
		ft_chek_null(jeu);
	}
	else if  (i == 0 && j == -1)
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, JOUEUR_LEFT, &jeu->largeur_carte, &jeu->hauteur_carte);
		ft_chek_null(jeu);
	}
	if (print)
		mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, (jeu->pos_joueur_y  + j)* TAILLE, (jeu->pos_joueur_x + i) * TAILLE);
	else
		mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, jeu->pos_joueur_y * TAILLE, jeu->pos_joueur_x  * TAILLE);
}

void print_image_2(t_carte *jeu, int i, int j)
{
    mlx_destroy_image(jeu->mlx, jeu->mlx_img); //knsuprimer image li precedente
    jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, ESPACE, &jeu->largeur_carte, &jeu->hauteur_carte);
	//faire une chek
	ft_chek_null(jeu);
    mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, jeu->pos_joueur_y * TAILLE, jeu->pos_joueur_x * TAILLE);
	print_image_3(jeu, i, j, true);
    update_move_count(jeu);
	jeu->pos_joueur_x += i;
	jeu->pos_joueur_y += j;
	if (!jeu->nbr_collect)
		print_door_out(jeu);
}

void	ft_move(t_carte **jeu, int i, int j)
{
	// hde chek 3la pleyer dyali ila kano 3ndo les cordoner b7ale enimi 7ite knt kl9a mochkil ila jito mn jnabe
	if ((*jeu)->carte[(*jeu)->pos_joueur_x + i][(*jeu)->pos_joueur_y + j] == 'X')
		enimi_win(jeu);
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
		player_win(jeu);
    // ft_print_movement(*jeu); 4adi n7ydha ondire hdi -> (*jeu)->nbr_mouve ++;
	(*jeu)->nbr_mouve ++;
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
    else if (click == 53)
		ft_sortie(jeu);
	return (0);
}