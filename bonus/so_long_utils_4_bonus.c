/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_4_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:10:49 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/21 14:58:14 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_door_out(t_carte *jeu)
{
	mlx_destroy_image(jeu->mlx, jeu->mlx_img);
	jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, DOOR_OPEN,
			&jeu->largeur_carte, &jeu->hauteur_carte);
	if (!jeu->mlx_img)
	{
		if (jeu->mlx_win)
			mlx_destroy_window(jeu->mlx, jeu->mlx_win);
		free_jeu(jeu);
		exit(1);
	}
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img,
		jeu->pos_door_y * TAILLE, jeu->pos_door_x * TAILLE);
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

void	aid_print_images_2(t_carte *jeu, int x, int y)
{
	if (jeu->carte[x][y] == 'C')
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, COLLECT,
				&jeu->largeur_carte, &jeu->hauteur_carte);
		ft_chek_etput(jeu, x, y);
	}
	else if (jeu->carte[x][y] == 'E')
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, DOOR,
				&jeu->largeur_carte, &jeu->hauteur_carte);
		ft_chek_etput(jeu, x, y);
	}
}