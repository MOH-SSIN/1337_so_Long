#include "so_long.h"

int	ft_exit(t_carte **jeu)
{
	ft_putstr_fd("Exit\n",1);
	free_jeu(*jeu);
	exit(0);
	return (0);
}

void ft_marque_collect(char **carte, int i, int j)
{
    if (carte[i][j] == '1' || carte[i][j] == 'V' || carte[i][j] == 'E')
        return;
    carte[i][j] = 'V';
    ft_marque_collect(carte, i + 1, j); // Bas
    ft_marque_collect(carte, i - 1, j); // Haut
    ft_marque_collect(carte, i, j + 1); // Droite
    ft_marque_collect(carte, i, j - 1); // Gauche
}
void ft_marque_door(char **carte, int i, int j)
{
    if (carte[i][j] == '1' || carte[i][j] == 'V')
        return;
    carte[i][j] = 'V';
    ft_marque_door(carte, i + 1, j); // Bas
    ft_marque_door(carte, i - 1, j); // Haut
    ft_marque_door(carte, i, j + 1); // Droite
    ft_marque_door(carte, i, j - 1); // Gauche
}
char **copie_map(char **carte)
{
	int		i;
	char	**copie;

	i = 0;
	while (carte[i])
		i++;
	copie = malloc((i + 1) * sizeof(char *));
	if (!copie)
		return (NULL);
	i = 0;
	while (carte[i])
	{
		copie[i] = ft_strdup(carte[i]);
		if (!copie[i])
		{
			free_copy_map(copie, i);
			return (NULL);
		}
		i++;
	}
	copie[i] = NULL;
	return (copie);
}
