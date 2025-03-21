/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:02:42 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/21 14:26:02 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	aid_verif_elements(char element, int *p, int *e, int *c)
{
	if (element == 'P')
		(*p)++;
	else if (element == 'E')
		(*e)++;
	else if (element == 'C')
		(*c)++;
	else if (element != '0' && element != '1')
		return (0);
	return (1);
}

int	get_position_player(char **copie, int *i, int *j)
{
	*i = 0;
	while (copie[*i])
	{
		*j = 0;
		while (copie[*i][*j])
		{
			if (copie[*i][*j] == 'P')
				return (1);
			(*j)++;
		}
		(*i)++;
	}
	return (0);
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

int	ft_presence_elemntes(char **copie)
{
	int	i;
	int	j;
	int	c;
	int	e;

	i = 0;
	c = 0;
	e = 0;
	while (copie[i])
	{
		j = 0;
		while (copie[i][j])
		{
			if (copie[i][j] == 'E')
				e++;
			else if (copie[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c == 0 && e == 0);
}
