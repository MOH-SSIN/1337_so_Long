#include "so_long_bonus.h"

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

void	print_image_4(t_carte **jeu, char image)
{
	mlx_destroy_image((*jeu)->mlx, (*jeu)->mlx_img); //knsuprimer image li precedente
	if (image == 'S')
	{
		(*jeu)->mlx_img = mlx_xpm_file_to_image((*jeu)->mlx, ESPACE, &(*jeu)->largeur_carte, &(*jeu)->hauteur_carte);
		mlx_put_image_to_window((*jeu)->mlx, (*jeu)->mlx_win, (*jeu)->mlx_img, (*jeu)->pos_ennemi_y * TAILLE, (*jeu)->pos_ennemi_x * TAILLE);
	}
	if (image == 'N')
	{
		(*jeu)->mlx_img = mlx_xpm_file_to_image((*jeu)->mlx, ENNEMI, &(*jeu)->largeur_carte, &(*jeu)->hauteur_carte);
		mlx_put_image_to_window((*jeu)->mlx, (*jeu)->mlx_win, (*jeu)->mlx_img, (*jeu)->pos_ennemi_y * TAILLE, (*jeu)->pos_ennemi_x * TAILLE);
	}

}

int move_enemy(t_carte **jeu)
{
    int next_x;

    if (++frame_count < 2000)
        return (0);
    frame_count = 0;

    // get_position_enimi(jeu);
    next_x = (*jeu)->pos_ennemi_x + direction;
    if ((*jeu)->carte[next_x][(*jeu)->pos_ennemi_y] == '1' || 
        (*jeu)->carte[next_x][(*jeu)->pos_ennemi_y] == 'C')
    {
        direction *= -1;
        next_x = (*jeu)->pos_ennemi_x + direction;
    }
	// hadi ztha 7ite chek li drt 3la plyer makafich hdi kat5ali ila enimi kano 3ndi nfse cordoner dyale player nkhroje hit lowla 7alte liya 4i mochkil dyale ila jite enimi mn jnabe ok
	// mohime lowla ila player mcha 3nde enimi ama hadi ila enim mcha 3nd player ok
    else if ((*jeu)->carte[next_x][(*jeu)->pos_ennemi_y] == 'P')
		enimi_win(jeu);
	//hna m4ndoze 7ta maykone player 9odame enimi
    (*jeu)->carte[(*jeu)->pos_ennemi_x][(*jeu)->pos_ennemi_y] = '0';
    print_image_4(jeu, 'S');
    (*jeu)->pos_ennemi_x = next_x;
    (*jeu)->carte[(*jeu)->pos_ennemi_x][(*jeu)->pos_ennemi_y] = 'X';
    print_image_4(jeu, 'N');
    return (0);
}

int init_jeu(t_carte **jeu)
{
    //initalisation dyal mlx
	position_enimi(jeu);//
	position_player(jeu);//hta hadi machi bdarora ndirha hit deja defini dans print_image(ila 7tyha ki stvolta !! hh)
	if ((*jeu)->carte[(*jeu)->pos_joueur_x ][(*jeu)->pos_joueur_y] == (*jeu)->carte[(*jeu)->pos_ennemi_x - 1][(*jeu)->pos_ennemi_y])
		enimi_win(jeu);
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
	mlx_string_put((*jeu)->mlx, (*jeu)->mlx_win, 0, 0, 0xFFFFFF, "MV:0");
    mlx_hook((*jeu)->mlx_win, 17, (1L<<0), ft_exit, jeu);
    mlx_hook((*jeu)->mlx_win, 2, (1L<<0), ft_keymove, jeu);
	mlx_loop_hook((*jeu)->mlx, move_enemy, jeu);
    mlx_loop((*jeu)->mlx);
    return (1);
}
