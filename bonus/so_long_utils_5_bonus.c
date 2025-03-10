/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_5_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:11:49 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/10 15:11:50 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_win(t_carte **jeu)
{
	ft_putstr_fd("You Win\n", 1);
	mlx_destroy_window((*jeu)->mlx, (*jeu)->mlx_win);//Fermer fenetre graphique cree par MiniLibX
	free_jeu(*jeu);
	exit(0);
}

void	enimi_win(t_carte **jeu)//yaser rba7e
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
char	*convertir_nbr_en_str(int nbr_mouve)
{
	char	*count_str;
	char	*string_put;

	count_str = ft_itoa(nbr_mouve);
	if (!count_str)
		return (NULL);
	string_put = ft_strjoin("MV:", count_str);
	free(count_str);
	return (string_put);
}

void	mettre_a_jour_image(t_carte *jeu)
{
	if (jeu->mlx_img)
		mlx_destroy_image(jeu->mlx, jeu->mlx_img);
	jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, MUR_2,
			&jeu->largeur_carte, &jeu->hauteur_carte);
	ft_chek_null(jeu);
	if (!jeu->mlx_img)
		return ;
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, 0, 0);
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, TAILLE, 0);
}