#include "so_long_bonus.h"


void free_jeu(t_carte *jeu)
{
	int	i;

	i = -1;
	while (jeu->carte[++i])
		free(jeu->carte[i]);
	free(jeu->carte);
	free(jeu);
}

void free_map(char **map)
{
    int i;

    i = -1;
    while (map[++i])
        free(map[i]);
    free(map);
}

void	free_copy_map(char **copie, int j)
{
	char	**temp;
	int		i;

	temp = copie;
	i = -1;
	while (++i < j)
		free(temp[j]);
	free(temp);
}