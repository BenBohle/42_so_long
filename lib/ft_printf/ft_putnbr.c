/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:47:18 by bbohle            #+#    #+#             */
/*   Updated: 2023/12/15 19:29:23 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	assign_nbr_helper(int *tmp, int *counter, int long *nlong, int n)
{
	*tmp = 0;
	*counter = 0;
	*nlong = n;
	if (*nlong < 0)
	{
		*nlong = *nlong * -1;
		*counter = ft_putchar('-');
		if (*counter == -1)
			return (-1);
	}
	return (0);
}

int	ft_putnbr(int n)
{
	int long	nlong;
	int			counter;
	int			tmp;

	if (assign_nbr_helper(&tmp, &counter, &nlong, n) == -1)
		return (-1);
	if (nlong >= 10)
	{
		tmp = counter;
		counter += ft_putnbr(nlong / 10);
		if (check_ft_checkformat(tmp, counter) == -1)
			return (-1);
		tmp = counter;
		counter += ft_putnbr(nlong % 10);
		if (check_ft_checkformat(tmp, counter) == -1)
			return (-1);
	}
	else
	{
		tmp = counter;
		counter += ft_putchar(nlong + '0');
		if (check_ft_checkformat(tmp, counter) == -1)
			return (-1);
	}
	return (counter);
}
