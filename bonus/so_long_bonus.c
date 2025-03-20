/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:12:33 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/10 14:20:26 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_so_long(t_carte **jeu)
{
	if (!verfication(*jeu))
	{
		ft_putstr_fd("Erreure Map\n", 2);
		free_jeu(*jeu);
		exit(1);
	}
	if (!init_jeu(jeu))
	{
		if ((*jeu)->mlx && (*jeu)->mlx_win)
			mlx_destroy_window((*jeu)->mlx, (*jeu)->mlx_win);
		exit(1);
	}
}

void	mohcine(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_carte	*jeu;

	atexit(mohcine);
	if (argc != 2 || !ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		ft_putstr_fd("Erreur dans argumente!\n", 2);
		return (1);
	}
	jeu = (t_carte *)malloc((sizeof(t_carte)));
	if (!jeu)
		return (1);
	jeu->carte = charger_carte(argv, &jeu);
	if (!jeu->carte)
	{
		ft_putstr_fd("Erreur de chargement!\n", 2);
		free(jeu);
		return (1);
	}
	ft_so_long(&jeu);
	free_jeu(jeu);
}
