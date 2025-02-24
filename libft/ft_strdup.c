/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:55:49 by mez-zahi          #+#    #+#             */
/*   Updated: 2024/11/08 14:38:47 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;
	size_t	size;

	i = -1;
	size = ft_strlen(s);
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (NULL);
	while (++i < size)
		ptr[i] = s[i];
	ptr[i] = '\0';
	return (ptr);
}
