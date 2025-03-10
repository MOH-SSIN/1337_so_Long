/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_3_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:10:44 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/10 15:10:45 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


void	update_move_count(t_carte *jeu)
{
	char	*string_put;

	string_put = convertir_nbr_en_str(jeu->nbr_mouve);
	if (!string_put)
	{
		mlx_destroy_window(jeu->mlx, jeu->mlx_win);
		free_jeu(jeu);
		exit(1);
	}
	mettre_a_jour_image(jeu);
	if (jeu->mlx_img)
		mlx_string_put(jeu->mlx, jeu->mlx_win, 0, 0, 0xFFFFFF, string_put);
	free(string_put);
}




void	print_image_3(t_carte *jeu, int i, int j, bool print)
{
	mlx_destroy_image(jeu->mlx, jeu->mlx_img);
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
    mlx_destroy_image(jeu->mlx, jeu->mlx_img);
    jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, ESPACE, &jeu->largeur_carte, &jeu->hauteur_carte);
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
	if ((*jeu)->carte[(*jeu)->pos_joueur_x + i][(*jeu)->pos_joueur_y + j] == 'X')
		enimi_win(jeu);
	if ((*jeu)->carte[(*jeu)->pos_joueur_x + i][(*jeu)->pos_joueur_y + j] == '1' 
			|| ((*jeu)->carte[(*jeu)->pos_joueur_x + i][(*jeu)->pos_joueur_y + j] == 'E' && (*jeu)->nbr_collect))
	{
		print_image_3(*jeu, i, j, false);
		return ;
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
	(*jeu)->nbr_mouve ++;
	print_image_2(*jeu, i, j);
}

int	ft_keymove(int click, t_carte **jeu)
{
	if (click == 126 || click == 13)
		ft_move(jeu, -1, 0);
	else if (click == 125 || click == 1)
		ft_move(jeu, 1, 0);
	else if (click == 124 || click == 2)
		ft_move(jeu, 0, 1);
	else if (click == 123 || click == 0)
		ft_move(jeu, 0, -1);
    else if (click == 53)
		ft_sortie(jeu);
	return (0);
}