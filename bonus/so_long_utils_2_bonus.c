/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:10:36 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/24 16:52:29 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	aid_verif_elements(char element, t_counts *counts)
{
	if (element == 'P')
		counts->p++;
	else if (element == 'E')
		counts->e++;
	else if (element == 'C')
		counts->c++;
	else if (element == 'X')
		counts->x++;
	else if (element != '0' && element != '1')
		return (0);
	return (1);
}

int	get_position_player(char **copie, int *i, int *j)
{
	*i = 0;
	while (copie[*i])
	{
		*j = 0;
		while (copie[*i][*j])
		{
			if (copie[*i][*j] == 'P')
				return (1);
			(*j)++;
		}
		(*i)++;
	}
	return (0);
}

void	ft_chek_etput(t_carte *jeu, int x, int y)
{
	ft_chek_null(jeu);
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, y * TAILLE, x
		* TAILLE);
}

int	ft_presence_elemntes(char **copie)
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	x;

	i = -1;
	c = 0;
	e = 0;
	x = 0;
	while (copie[++i])
	{
		j = 0;
		while (copie[i][j])
		{
			if (copie[i][j] == 'E')
				e++;
			else if (copie[i][j] == 'C')
				c++;
			else if (copie[i][j] == 'X')
				x++;
			j++;
		}
	}
	return (c == 0 && e == 0 && x == 0);
}

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
