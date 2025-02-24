/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:52:47 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/02/12 17:58:06 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
static int	ft_ft(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

static void ft_ptint_error(long result)
{
	if (result > INT_MAX )
	{
		write(1,"Error\n",6);
		exit(1);
	}
}

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
			return (ft_ft(sign));
		result = result * 10 + (str[i] - '0');
		ft_ptint_error(result);
		i++;
	}
	return (result * sign);
}


