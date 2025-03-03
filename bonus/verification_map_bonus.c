#include "so_long_bonus.h"

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
    int x;

    p = 0;
    e = 0;
    c = 0;
    i = 0;
    x = 0;
    while (carte[i])
    {
        j = 0;
        while (carte[i][j])
        {
            if (!aid_verif_elements(carte[i][j], &p, &e, &c, &x))
                return (0);
            j++;
        }
        i++;
    }
    if (p != 1 || e != 1 || x !=  1 || c < 1)
        return (0);
    return (1);
}

int est_bloque(char **carte)
{
	char	**copie ;
	int	i ;
	int	j;

	copie = copie_map(carte);
	if (!copie)
		return (0);
	// trouver position dyal player
	if (get_position_player(copie, &i, &j))
		ft_marque(copie, i, j);
	//apres kanvirifier wach E et C wach atteignables
	if (ft_presence_elemntes(copie))
	{
		free_map(copie);
		return (1);
	}
	free_map(copie);
	return (0);
}

int verfication(t_carte *jeu)
{
	if (!verfi_rectan(jeu->carte))
	{
		ft_putstr_fd("carte n'est pas rectangulaire\n",2);
		return (0);
	}
	if (!verif_murs(jeu->carte))
	{
		ft_putstr_fd("carte n'est pas entourée de murs\n",2);
		return (0);
	}
	if (!verif_elements(jeu->carte))
	{
		ft_putstr_fd("Problème avec les éléments P, E, ou C\n", 2);
		return (0);
	}
	if (!est_bloque(jeu->carte))
	{
		ft_putstr_fd("L'élément est bloqué\n", 2);
		return (0);
	}
	return (1);
}