/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:02:59 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/03/20 14:35:09 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	free_jeu(t_carte *jeu)
{
	if (!jeu)
		return ;
	if (jeu->carte)
		free_map(jeu->carte);
	free(jeu);
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

void	free_map_copy(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
