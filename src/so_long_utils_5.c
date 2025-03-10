/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:02:31 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/10 14:07:09 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_win(t_carte **jeu)
{
	ft_print_movement(*jeu);
	ft_putstr_fd("You Win\n", 1);
	mlx_destroy_window((*jeu)->mlx, (*jeu)->mlx_win);
	free_jeu(*jeu);
	exit(0);
}

void	enimi_win(t_carte **jeu)
{
	ft_putstr_fd("Ennemi rba7e\n", 1);
	if (!jeu || !*jeu || !(*jeu)->mlx || !(*jeu)->mlx_win)
		exit(1);
	mlx_destroy_window((*jeu)->mlx, (*jeu)->mlx_win);
	free_jeu(*jeu);
	exit(0);
}

void	ft_sortie(t_carte **jeu)
{
	ft_putstr_fd("Exit\n", 1);
	mlx_destroy_window((*jeu)->mlx, (*jeu)->mlx_win);
	free_jeu(*jeu);
	exit(0);
}
