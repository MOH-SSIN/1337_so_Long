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
