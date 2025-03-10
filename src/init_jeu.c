#include "so_long.h"
//une remarque x->i(verticale) et ona y->j(horizotal)
// hit la fonction  mlx_put_image_to_window katakhose la valeure horizotal 3ade virtucale 
void aid_print_images(t_carte *jeu, int x, int y)
{
	if (jeu->carte[x][y] == '1')
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, MUR, &jeu->largeur_carte, &jeu->hauteur_carte);
		mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, y * TAILLE, x * TAILLE);
	}
	else if (jeu->carte[x][y] == '0')
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, ESPACE, &jeu->largeur_carte, &jeu->hauteur_carte);
		mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, y * TAILLE, x * TAILLE);
	}
	else if (jeu->carte[x][y] == 'P')
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, JOUEUR_RIGHT, &jeu->largeur_carte, &jeu->hauteur_carte);
		mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, y * TAILLE, x * TAILLE);
	}
	else if (jeu->carte[x][y] == 'C')
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, COLLECT, &jeu->largeur_carte, &jeu->hauteur_carte);
		mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, y * TAILLE, x * TAILLE);
	}
	else if (jeu->carte[x][y] == 'E')
	{
		jeu->mlx_img = mlx_xpm_file_to_image(jeu->mlx, DOOR, &jeu->largeur_carte, &jeu->hauteur_carte);
		mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->mlx_img, y * TAILLE, x * TAILLE);
	}
}

void print_images(t_carte *jeu)
{
    int i;
    int j;

    i = -1;
    while (jeu->carte[++i])
    {
        j = -1;
        while (jeu->carte[i][++j])
        {
			//ona kn printi kn definire la position de joueur
			if (jeu->carte[i][j] == 'P')
			{
				jeu->pos_joueur_x= i;
				jeu->pos_joueur_y = j;
			}
			if (jeu->carte[i][j] == 'E')
			{
				jeu->pos_door_x= i;
				jeu->pos_door_y = j;
			}
			// hna kn calcluer le nbr de collect
			else if (jeu->carte[i][j] == 'C')
				jeu->nbr_collect++;
			//cette fonction cat aficher les image dans fenetre
            aid_print_images(jeu, i, j);
        }
    }
}


void	position_player(t_carte **jeu)
{
	int	i;
	int	j;

    i = 0;
    while ((*jeu)->carte[i])
    {
        j = 0;
        while ((*jeu)->carte[i][j])
        {
            if ((*jeu)->carte[i][j] == 'P')
			{
				(*jeu)->pos_joueur_x = i;
				(*jeu)->pos_joueur_y = j;
				return ;
			}
            (j)++;
        }
        (i)++;
    }
}

int init_jeu(t_carte **jeu)
{
    //initalisation dyal mlx
	// position_player(jeu);// n9dre mndirhache hna 7ite deja kn defini position player dans fonction print_image
    (*jeu)->mlx = mlx_init();
    if (!(*jeu)->mlx)
    {
        // free_jeu(*jeu);hadi blach deja ila 5rjate b false 5asi n free_jeu
        return (0);
    }
    // ouvrire dyale fenetre
    (*jeu)->mlx_win = mlx_new_window((*jeu)->mlx, (*jeu)->largeur_carte * TAILLE,
                (*jeu)->hauteur_carte * TAILLE, "so_long");
    if (!((*jeu)->mlx_win))
    {
        // free_jeu(*jeu);hadi blach deja ila 5rjate b false 5asi n free_jeu
        return (0);
    }
    print_images(*jeu);
	(*jeu)->nbr_mouve = 0;// inistalisation  dyale nbr de move en 0;
    mlx_hook((*jeu)->mlx_win, 17, (1L<<0), ft_exit, jeu);
    mlx_hook((*jeu)->mlx_win, 2, (1L<<0), ft_keymove, jeu);
    mlx_loop((*jeu)->mlx);
    return (1);
}
