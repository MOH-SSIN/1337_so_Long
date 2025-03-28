/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:02:25 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/28 13:40:46 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdbool.h>

# define TAILLE 50
# define ESPACE "image_1/baground.xpm"
# define COLLECT "image_1/Collect.xpm"
# define DOOR "image_1/door_close.xpm"
# define DOOR_OPEN "image_1/door_open.xpm"
# define JOUEUR_BOTTOM "image_1/pac_man_botom.xpm"
# define JOUEUR_TOP "image_1/pac_man_top.xpm"
# define JOUEUR_RIGHT "image_1/pac_man_right.xpm"
# define JOUEUR_LEFT "image_1/pac_man_left.xpm"
# define MUR "image_1/wall.xpm"
# define MUR_2 "image_1/wall.xpm"
# define ENNEMI "image_1/Enemy.xpm"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

typedef struct s_carte
{
	int		direction;
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	**carte;
	int		nbr_collect;
	int		largeur_carte;
	int		hauteur_carte;
	int		pos_joueur_x;
	int		pos_joueur_y;
	int		pos_ennemi_x;
	int		pos_ennemi_y;
	bool	partie_terminee;
	int		pos_door_x;
	int		pos_door_y;
	int		nbr_mouve;
}			t_carte;

char		**charger_carte(char *av[], t_carte **jeu);

void		free_jeu(t_carte *jeu);
void		free_map(char **map);
void		free_copy_map(char **copie, int j);
void		free_map_copy(char **map);

bool		initialiser_jeu(t_carte **jeu);

int			verfication(t_carte *jeu);

int			init_jeu(t_carte **jeu);

int			ft_exit(t_carte **jeu);
int			ft_keymove(int click, t_carte **jeu);
char		**copie_map(char **carte);
void		ft_marque(char **carte, int i, int j);

int			aid_verif_elements(char element, int *p, int *e, int *c);
int			get_position_player(char **copie, int *i, int *j);
int			ft_presence_elemntes(char **copie);
void		position_player(t_carte **jeu);

void		print_door_out(t_carte *jeu);
void		ft_print_movement(t_carte *jeu);

void		player_win(t_carte **jeu);
void		enimi_win(t_carte **jeu);
void		ft_sortie(t_carte **jeu);

void		ft_chek_null(t_carte *jeu);

int			verfi_rectan(char **carte);
int			verif_murs(char **carte);
int			verif_elements(char **carte);
int			collecte_est_bloque(char **carte);
int			door_est_bloque(char **carte);

void		ft_marque_collect(char **carte, int i, int j);
void		ft_marque_door(char **carte, int i, int j);

char		*get_next_line(int fd);
void		*ft_free(char *ptr1, char *ptr2);

void		ft_chek_null(t_carte *jeu);

#endif
