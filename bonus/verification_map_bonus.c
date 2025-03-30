/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_map_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:11:52 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/30 13:19:32 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_chek(t_carte **jeu)
{
	int	x;
	int	y;

	x = (*jeu)->pos_ennemi_x;
	y = (*jeu)->pos_ennemi_y;
	if (((*jeu)->carte[x - 1][y] == '1' || (*jeu)->carte[x - 1][y] == 'C'
			|| (*jeu)->carte[x - 1][y] == 'E')
		&& ((*jeu)->carte[x + 1][y] == '1' || (*jeu)->carte[x + 1][y] == 'C'
			|| (*jeu)->carte[x + 1][y] == 'E'))
		return (1);
	return (0);
}

int	verfication(t_carte *jeu)
{
	if (!verfi_rectan(jeu->carte))
	{
		ft_putstr_fd("carte n'est pas rectangulaire\n", 2);
		return (0);
	}
	if (!verif_murs(jeu->carte))
	{
		ft_putstr_fd("carte n'est pas entourée de murs\n", 2);
		return (0);
	}
	if (!verif_elements(jeu->carte))
	{
		ft_putstr_fd("Problème avec les éléments P, E, C, ou X\n", 2);
		return (0);
	}
	if (!door_est_bloque(jeu->carte) || !collecte_est_bloque(jeu->carte))
	{
		ft_putstr_fd("element blouquer\n", 2);
		return (0);
	}
	return (1);
}
