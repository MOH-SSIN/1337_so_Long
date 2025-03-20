/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:02:35 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/10 15:32:58 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_door_out(t_carte *jeu)
{
	mlx_destroy_image(jeu->mlx, jeu->mlx_img);
	jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, DOOR_OPEN,
			&jeu->largeur_carte, &jeu->hauteur_carte);
	if (!jeu->mlx_img)
	{
		ft_putstr_fd("overture image door echoue\n", 1);
		if (jeu->mlx_win)
			mlx_destroy_window(jeu->mlx, jeu->mlx_win);
		free_jeu(jeu);
		exit(1);
	}
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img,
		jeu->pos_door_y * TAILLE, jeu->pos_door_x * TAILLE);
}

void	ft_print_movement(t_carte *jeu)
{
	char	*mv;

	jeu->nbr_mouve++;
	mv = ft_itoa(jeu->nbr_mouve);
	if (!mv)
	{
		if (jeu->mlx_win)
			mlx_destroy_window(jeu->mlx, jeu->mlx_win);
		exit(1);
	}
	write(1, "MV:", 3);
	write(1, mv, ft_strlen(mv));
	free(mv);
	write(1, "\n", 1);
}
