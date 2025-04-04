/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_map_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:02:20 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/24 16:52:56 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	verfi_rectan(char **carte)
{
	int	largeur;
	int	i;

	if (!carte || !carte[0])
		return (0);
	largeur = (int)ft_strlen(carte[0]);
	i = 1;
	while (carte[i])
	{
		if ((int)ft_strlen(carte[i]) != largeur)
			return (0);
		i++;
	}
	return (1);
}

int	verif_murs(char **carte)
{
	int	largeur;
	int	hauteur;
	int	i;

	largeur = (int)ft_strlen(carte[0]);
	hauteur = 0;
	while (carte[hauteur])
		hauteur++;
	i = 0;
	while (carte[0][i])
	{
		if (carte[0][i] != '1' || carte[hauteur - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (carte[i])
	{
		if (carte[i][0] != '1' || carte[i][largeur - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	verif_elements(char **carte)
{
	int			i;
	int			j;
	t_counts	counts;

	counts.p = 0;
	counts.e = 0;
	counts.c = 0;
	counts.x = 0;
	i = -1;
	while (carte[++i])
	{
		j = 0;
		while (carte[i][j])
		{
			if (!aid_verif_elements(carte[i][j], &counts))
				return (0);
			j++;
		}
	}
	if (counts.p != 1 || counts.e != 1 || counts.x != 1 || counts.c < 1)
		return (0);
	return (1);
}

int	collecte_est_bloque(char **carte)
{
	char	**copie;
	int		i;
	int		j;

	copie = copie_map(carte);
	if (!copie)
		return (0);
	if (get_position_player(copie, &i, &j))
		ft_marque_collect(copie, i, j);
	i = -1;
	while (copie[++i])
	{
		j = -1;
		while (copie[i][++j])
		{
			if (copie[i][j] == 'C' && copie[i][j] != 'V')
			{
				free_map_copy(copie);
				return (0);
			}
		}
	}
	free_map_copy(copie);
	return (1);
}

int	door_est_bloque(char **carte)
{
	char	**copie;
	int		i;
	int		j;

	copie = copie_map(carte);
	if (!copie)
		return (0);
	if (get_position_player(copie, &i, &j))
		ft_marque_door(copie, i, j);
	if (ft_presence_elemntes(copie))
	{
		free_map_copy(copie);
		return (1);
	}
	free_map_copy(copie);
	return (0);
}
