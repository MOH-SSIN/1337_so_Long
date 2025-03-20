/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_map_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:11:52 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/20 14:47:00 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		ft_putstr_fd("Problème avec les éléments P, E, ou C\n", 2);
		return (0);
	}
	if (!door_est_bloque(jeu->carte) || !collecte_est_bloque(jeu->carte))
	{
		ft_putstr_fd("element blouquer\n", 2);
		return (0);
	}
	return (1);
}
