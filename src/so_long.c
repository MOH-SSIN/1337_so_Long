#include "so_long.h"

//pour print map
// void	print_map(t_carte *jeu)
// {
// 	int i = 0;
// 	int j;
// 	while (jeu->carte[i])
// 	{
// 		j = 0;
// 		while (jeu->carte[i][j])
// 		{
// 			printf("%c",jeu->carte[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

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
		mlx_destroy_window((*jeu)->mlx, (*jeu)->mlx_win);//hna n9dre njm3e hdo fune fois mchtarkine fhde les line !!
		free_jeu(*jeu);
		exit(1);
	}
	
}

int main(int argc, char **argv)
{
    t_carte *jeu;
    // hna verification des argumente 
    if (argc != 2 || !ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
    {
        ft_putstr_fd("Erreur dans argumente!\n", 2);
        return (1);
    }
    //apes kan alouer la memoire la structure de jeu
    jeu = (t_carte *)malloc((sizeof(t_carte)));
    if (!jeu)
        return (1);
    // kan carger la carte
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
