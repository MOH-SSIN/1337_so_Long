#include "so_long.h"

//hna verfi_rectangilaire 
int verfi_rectan(char **carte)
{
    int largeur;
    int i;

    if (!carte || !carte[0])
        return (0);
    largeur = (int)ft_strlen(carte[0]);
    i = 1;
    while (carte[i])
    {
        if ((int)ft_strlen(carte[i]) != largeur)
            return (0);
        i++;
    }
    return (1);
}
//verif_murs wach dayra b les 1
int verif_murs(char **carte)
{
    int largeur;
    int hauteur;
    int i;

    largeur = (int)ft_strlen(carte[0]);
    hauteur = 0;
    while (carte[hauteur])
        hauteur++;
    i = 0;
    while (carte[0][i])
    {
        if (carte[0][i] != '1' || carte[hauteur - 1][i] != '1')
            return (0);
        i++;
    }
    i = 0;
    while (carte[i])
    {
        if (carte[i][0] != '1' || carte[i][largeur - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}
// verification dyale element ok
int verif_elements(char **carte)
{
    int i;
    int j;
    int p;
    int e;
    int c;

    p = 0;
    e = 0;
    c = 0;
    i = 0;
    while (carte[i])
    {
        j = 0;
        while (carte[i][j])
        {
            if (!aid_verif_elements(carte[i][j], &p, &e, &c))
                return (0);
            j++;
        }
        i++;
    }
    if (p != 1 || e != 1 || c < 1)
        return (0);
    return (1);
}

int collecte_est_bloque(char **carte)
{
    char    **copie;
    int     i;
    int     j;

    copie = copie_map(carte);
    if (!copie)
        return (0);
    if (get_position_player(copie, &i, &j))
        ft_marque_collect(copie, i, j);
    i = -1;
    while (copie[++i])
    {
        j = -1;
        while (copie[i][++j])
        {
            if (copie[i][j] == 'C' && copie[i][j] != 'V')
            {
                free(copie);
                return (0); // collecte bloquer
            }
        }
    }
    free(copie);
    return (1); // colecte acessible
}
int door_est_bloque(char **carte)
{
	char	**copie ;
	int	i ;
	int	j;

	copie = copie_map(carte);
	if (!copie)
		return (0);
	// trouver position dyal player
	if (get_position_player(copie, &i, &j))
		ft_marque_door(copie, i, j);
	//apres kanvirifier wach E et C wach atteignables
	if (ft_presence_elemntes(copie))
	{
		free_map(copie);
		return (1);
	}
	free_map(copie);
	return (0);
}
