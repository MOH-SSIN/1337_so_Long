/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:10:18 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/30 13:30:19 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdbool.h>

# define TAILLE 50
# define ESPACE "textures/baground.xpm"
# define COLLECT "textures/Collect.xpm"
# define DOOR "textures/door_close.xpm"
# define DOOR_OPEN "textures/door_open.xpm"
# define JOUEUR_BOTTOM "textures/pac_man_botom.xpm"
# define JOUEUR_TOP "textures/pac_man_top.xpm"
# define JOUEUR_RIGHT "textures/pac_man_right.xpm"
# define JOUEUR_LEFT "textures/pac_man_left.xpm"
# define MUR "textures/wall.xpm"
# define MUR_2 "textures/wall.xpm"
# define ENNEMI "textures/Enemy.xpm"

typedef struct s_carte
{
	int		direction;
	int		frame_count;
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

typedef struct s_counts
{
	int		p;
	int		e;
	int		c;
	int		x;
}			t_counts;

char		**charger_carte(char *av[], t_carte **jeu);

void		free_jeu(t_carte *jeu);
void		free_map(char **map);
void		free_copy_map(char **copie, int j);
void		free_map_copy(char **map);

bool		initialiser_jeu(t_carte **jeu);

int			verfication(t_carte *jeu);
int			ft_chek(t_carte **jeu);

int			init_jeu(t_carte **jeu);

int			ft_exit(t_carte **jeu);
int			ft_keymove(int click, t_carte **jeu);
int			is_valid_enemy_move(t_carte *jeu, int next_x, int next_y);
char		**copie_map(char **carte);
void		ft_marque(char **carte, int i, int j);
void		aid_print_images_2(t_carte *jeu, int x, int y);

int			aid_verif_elements(char element, t_counts *counts);
int			get_position_player(char **copie, int *i, int *j);
int			ft_presence_elemntes(char **copie);
void		update_move_count(t_carte *jeu);

void		print_door_out(t_carte *jeu);
void		ft_print_movement(t_carte *jeu);
void		position_enimi(t_carte **jeu);
void		position_player(t_carte **jeu);

void		player_win(t_carte **jeu);
void		enimi_win(t_carte **jeu);
void		ft_sortie(t_carte **jeu);

void		ft_chek_null(t_carte *jeu);

int			verfi_rectan(char **carte);
int			verif_murs(char **carte);
int			verif_elements(char **carte);
int			collecte_est_bloque(char **carte);
int			door_est_bloque(char **carte);

// utils1
void		ft_marque_collect(char **carte, int i, int j);
void		ft_marque_door(char **carte, int i, int j);

// gnl
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

char		*get_next_line(int fd);
void		*ft_free(char *ptr1, char *ptr2);

void		ft_chek_null(t_carte *jeu);
void		ft_chek_etput(t_carte *jeu, int x, int y);
char		*convertir_nbr_en_str(int nbr_mouve);
void		mettre_a_jour_image(t_carte *jeu);
#endif