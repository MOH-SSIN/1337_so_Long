/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:10:32 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/10 15:10:33 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_exit(t_carte **jeu)
{
	ft_putstr_fd("Exit\n",1);
	mlx_destroy_window((*jeu)->mlx, (*jeu)->mlx_win);
	free_jeu(*jeu);
	exit(0);
	return (0);
}

void ft_chek_null(t_carte *jeu)
{
	if (!jeu->mlx_img)
	{
		ft_putstr_fd("image non valid\n",1);
		mlx_destroy_window(jeu->mlx, jeu->mlx_win);
		free_map(jeu->carte);
		exit(1);
	}
}

void ft_marque_collect(char **carte, int i, int j)
{
    if (carte[i][j] == '1' || carte[i][j] == 'V' || carte[i][j] == 'E')
        return;
    carte[i][j] = 'V';
    ft_marque_collect(carte, i + 1, j);
    ft_marque_collect(carte, i - 1, j);
    ft_marque_collect(carte, i, j + 1);
    ft_marque_collect(carte, i, j - 1);
}
void ft_marque_door(char **carte, int i, int j)
{
    if (carte[i][j] == '1' || carte[i][j] == 'V')
        return;
    carte[i][j] = 'V';
    ft_marque_door(carte, i + 1, j);
    ft_marque_door(carte, i - 1, j);
    ft_marque_door(carte, i, j + 1);
    ft_marque_door(carte, i, j - 1);
}
char **copie_map(char **carte)
{
	int		i;
	char	**copie;

	i = 0;
	while (carte[i])
		i++;
	copie = malloc((i + 1) * sizeof(char *));
	if (!copie)
		return (NULL);
	i = 0;
	while (carte[i])
	{
		copie[i] = ft_strdup(carte[i]);
		if (!copie[i])
		{
			free_copy_map(copie, i);
			return (NULL);
		}
		i++;
	}
	copie[i] = NULL;
	return (copie);
}
