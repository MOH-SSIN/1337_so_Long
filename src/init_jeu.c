/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_jeu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:02:51 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/10 14:47:32 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_chek_etput(t_carte *jeu, int x, int y)
{
	ft_chek_null(jeu);
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, y * TAILLE, x * TAILLE);
}

void aid_print_images(t_carte *jeu, int x, int y)
{
	if (jeu->carte[x][y] == '1')
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, MUR, &jeu->largeur_carte, &jeu->hauteur_carte);
		ft_chek_etput(jeu, x, y);
	}
	else if (jeu->carte[x][y] == '0')
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, ESPACE, &jeu->largeur_carte, &jeu->hauteur_carte);
		ft_chek_etput(jeu, x, y);
	}
	else if (jeu->carte[x][y] == 'P')
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, JOUEUR_RIGHT, &jeu->largeur_carte, &jeu->hauteur_carte);
		ft_chek_etput(jeu, x, y);
	}
	else if (jeu->carte[x][y] == 'C')
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, COLLECT, &jeu->largeur_carte, &jeu->hauteur_carte);
		ft_chek_etput(jeu, x, y);
	}
	else if (jeu->carte[x][y] == 'E')
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, DOOR, &jeu->largeur_carte, &jeu->hauteur_carte);
		ft_chek_etput(jeu, x, y);
	}
}

void print_images(t_carte *jeu)
{
    int i;
    int j;

    i = -1;
    while (jeu->carte[++i])
    {
        j = -1;
        while (jeu->carte[i][++j])
        {
			if (jeu->carte[i][j] == 'P')
			{
				jeu->pos_joueur_x= i;
				jeu->pos_joueur_y = j;
			}
			if (jeu->carte[i][j] == 'E')
			{
				jeu->pos_door_x= i;
				jeu->pos_door_y = j;
			}
			else if (jeu->carte[i][j] == 'C')
				jeu->nbr_collect++;
            aid_print_images(jeu, i, j);
        }
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

int init_jeu(t_carte **jeu)
{
    (*jeu)->mlx = mlx_init();
    if (!(*jeu)->mlx)
        return (0);
    (*jeu)->mlx_win = mlx_new_window((*jeu)->mlx, (*jeu)->largeur_carte * TAILLE,
                (*jeu)->hauteur_carte * TAILLE, "so_long");
    if (!((*jeu)->mlx_win))
        return (0);
    print_images(*jeu);
	(*jeu)->nbr_mouve = 0;
    mlx_hook((*jeu)->mlx_win, 17, (1L<<0), ft_exit, jeu);
    mlx_hook((*jeu)->mlx_win, 2, (1L<<0), ft_keymove, jeu);
    mlx_loop((*jeu)->mlx);
    return (1);
}
