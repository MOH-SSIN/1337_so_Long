/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_carte_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:14:09 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/10 14:27:20 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int cal_largeur(char **carte)
{
    int largeur;

    largeur = 0;
    while(carte[0][largeur])
        largeur++;
    return (largeur);
}

int cal_hauteur(char **carte)
{
    int hauteur;

    hauteur = 0;
    while(carte[hauteur])
        hauteur++;
    return (hauteur);
}


char *lire_carte(int fd)
{
    char *line;
    char *temp_line;
    char *temp;

    line = ft_strdup("");
    if (!line)
        return (NULL);
    temp_line = get_next_line(fd);
    while (temp_line)
    {
        temp = ft_strjoin(line, temp_line);
        free(temp_line);
        free(line);
        if (!temp)
            return (NULL);
        line = temp;
        temp_line = get_next_line(fd);
    }
    return (line);
}

void cal_lar_hau(t_carte **jeu)
{
    (*jeu)->largeur_carte = cal_largeur((*jeu)->carte);
    (*jeu)->hauteur_carte = cal_hauteur((*jeu)->carte);
}

char **charger_carte(char **argv, t_carte **jeu)
{
    int fd;
    char *line;

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("Erreur d'ouverture\n", 2);
        return (NULL);
    }
    line = lire_carte(fd);
    close(fd);
    if (!line)
    {
        ft_putstr_fd("Erreur de lecture\n", 2);
        return (NULL);
    }
    (*jeu)->carte = ft_split(line, '\n');
    free(line);
    if (!(*jeu)->carte)
    {
        ft_putstr_fd("Erreur du découpage\n", 2);
        return (NULL);
    }
    cal_lar_hau(jeu);
    return ((*jeu)->carte);
}
