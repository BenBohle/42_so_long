/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:03:07 by bbohle            #+#    #+#             */
/*   Updated: 2023/11/24 16:28:43 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoicheck(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\v' || c == '\f')
	{
		return (1);
	}
	else if (c == '+' || c == '-')
	{
		return (2);
	}
	else if (ft_isdigit(c) == 1)
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}

int	ft_atoi(const char *str)
{
	int		counter;
	int		number;
	char	minusplus;

	counter = 0;
	number = 0;
	minusplus = 0;
	while (ft_atoicheck(str[counter]) >= 1 && minusplus == 0)
	{
		if (ft_atoicheck(str[counter]) == 2)
		{
			minusplus = str[counter];
		}
		counter++;
	}
	while (ft_isdigit(str[counter]) == 1)
	{
		number = number * 10 + (str[counter] - 48);
		counter++;
	}
	if (minusplus == '-')
		return (-number);
	return (number);
}
