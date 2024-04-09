/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 05:59:44 by bbohle            #+#    #+#             */
/*   Updated: 2023/11/24 16:31:03 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_vorzeichen(int n)
{
	int	minusplus;

	minusplus = 0;
	if (n < 0)
	{
		minusplus = 1;
		n = -n;
	}
	return (minusplus);
}

int	ft_newn(int n)
{
	if (n < 0)
	{
		n = -n;
	}
	return (n);
}

int	ft_digits(int n)
{
	int long	digits;

	digits = 1;
	while (n / 10 != 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

char	*ft_dingscheck(void)
{
	char	*string;

	string = (char *)malloc(12);
	if (string != NULL)
	{
		ft_strlcpy(string, "-2147483648", 12);
	}
	else
	{
		return (NULL);
	}
	return (string);
}

char	*ft_itoa(int n)
{
	int long	counter;
	int long	minusplus;
	int long	digits;
	char		*resub;

	if (n == -2147483648)
		return (ft_dingscheck());
	minusplus = ft_vorzeichen(n);
	digits = ft_digits(n);
	n = ft_newn(n);
	resub = (char *)malloc(digits + minusplus + 1);
	if (resub == NULL)
		return (NULL);
	counter = digits + minusplus;
	resub[counter] = '\0';
	while (digits > 0)
	{
		resub[--counter] = '0' + (n % 10);
		n /= 10;
		digits--;
	}
	if (minusplus > 0)
		resub[0] = '-';
	return (resub);
}
