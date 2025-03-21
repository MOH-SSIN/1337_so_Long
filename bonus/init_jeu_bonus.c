/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_jeu_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:41:31 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/21 14:54:02 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	aid_print_images(t_carte *jeu, int x, int y)
{
	if (jeu->carte[x][y] == '1')
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, MUR, &jeu->largeur_carte,
				&jeu->hauteur_carte);
		ft_chek_etput(jeu, x, y);
	}
	else if (jeu->carte[x][y] == '0')
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, ESPACE,
				&jeu->largeur_carte, &jeu->hauteur_carte);
		ft_chek_etput(jeu, x, y);
	}
	else if (jeu->carte[x][y] == 'P')
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, JOUEUR_RIGHT,
				&jeu->largeur_carte, &jeu->hauteur_carte);
		ft_chek_etput(jeu, x, y);
	}
	aid_print_images_2(jeu, x, y);
}

void	print_images(t_carte *jeu)
{
	int	i;
	int	j;

	i = -1;
	while (jeu->carte[++i])
	{
		j = -1;
		while (jeu->carte[i][++j])
		{
			if (jeu->carte[i][j] == 'P')
			{
				jeu->pos_joueur_x = i;
				jeu->pos_joueur_y = j;
			}
			if (jeu->carte[i][j] == 'E')
			{
				jeu->pos_door_x = i;
				jeu->pos_door_y = j;
			}
			else if (jeu->carte[i][j] == 'C')
				jeu->nbr_collect++;
			aid_print_images(jeu, i, j);
		}
	}
}

void	print_image_4(t_carte **jeu, char image)
{
	mlx_destroy_image((*jeu)->mlx, (*jeu)->mlx_img);
	if (image == 'S')
	{
		(*jeu)->mlx_img = mlx_xpm_file_to_image((*jeu)->mlx, ESPACE,
				&(*jeu)->largeur_carte, &(*jeu)->hauteur_carte);
		ft_chek_null(*jeu);
		mlx_put_image_to_window((*jeu)->mlx, (*jeu)->mlx_win, (*jeu)->mlx_img,
			(*jeu)->pos_ennemi_y * TAILLE, (*jeu)->pos_ennemi_x * TAILLE);
	}
	if (image == 'N')
	{
		(*jeu)->mlx_img = mlx_xpm_file_to_image((*jeu)->mlx, ENNEMI,
				&(*jeu)->largeur_carte, &(*jeu)->hauteur_carte);
		ft_chek_null(*jeu);
		mlx_put_image_to_window((*jeu)->mlx, (*jeu)->mlx_win, (*jeu)->mlx_img,
			(*jeu)->pos_ennemi_y * TAILLE, (*jeu)->pos_ennemi_x * TAILLE);
	}
}

int	move_enemy(t_carte **jeu)
{
	int	next_x;

	if (++frame_count < 2000)
		return (0);
	frame_count = 0;
	next_x = (*jeu)->pos_ennemi_x + direction;
	if ((*jeu)->carte[next_x][(*jeu)->pos_ennemi_y] == '1'
		|| (*jeu)->carte[next_x][(*jeu)->pos_ennemi_y] == 'C')
	{
		direction *= -1;
		next_x = (*jeu)->pos_ennemi_x + direction;
	}
	else if ((*jeu)->carte[next_x][(*jeu)->pos_ennemi_y] == 'P')
		enimi_win(jeu);
	(*jeu)->carte[(*jeu)->pos_ennemi_x][(*jeu)->pos_ennemi_y] = '0';
	print_image_4(jeu, 'S');
	(*jeu)->pos_ennemi_x = next_x;
	(*jeu)->carte[(*jeu)->pos_ennemi_x][(*jeu)->pos_ennemi_y] = 'X';
	print_image_4(jeu, 'N');
	return (0);
}

int	init_jeu(t_carte **jeu)
{
	position_enimi(jeu);
	position_player(jeu);
	if ((*jeu)->carte[(*jeu)->pos_joueur_x][(*jeu)->pos_joueur_y] ==
		(*jeu)->carte[(*jeu)->pos_ennemi_x - 1][(*jeu)->pos_ennemi_y])
		enimi_win(jeu);
	(*jeu)->mlx = mlx_init();
	if (!(*jeu)->mlx)
		return (0);
	(*jeu)->mlx_win = mlx_new_window((*jeu)->mlx, (*jeu)->largeur_carte
			* TAILLE, (*jeu)->hauteur_carte * TAILLE, "so_long");
	if (!((*jeu)->mlx_win))
		return (0);
	print_images(*jeu);
	(*jeu)->nbr_mouve = 0;
	mlx_string_put((*jeu)->mlx, (*jeu)->mlx_win, 0, 0, 0xFFFFFF, "MV:0");
	mlx_hook((*jeu)->mlx_win, 17, (1L << 0), ft_exit, jeu);
	mlx_hook((*jeu)->mlx_win, 2, (1L << 0), ft_keymove, jeu);
	mlx_loop_hook((*jeu)->mlx, move_enemy, jeu);
	mlx_loop((*jeu)->mlx);
	return (1);
}
