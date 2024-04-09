/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:35:59 by bbohle            #+#    #+#             */
/*   Updated: 2023/12/15 20:44:47 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	assign_ft_putunsigned_helper(int *counter, int *pre_value)
{
	*counter = 0;
	*pre_value = 0;
}

int	ft_putunsigned(unsigned int n)
{
	unsigned int long	nlong;
	int					counter;
	int					pre_value;

	nlong = n;
	assign_ft_putunsigned_helper(&counter, &pre_value);
	if (nlong >= 10)
	{
		pre_value = counter;
		counter += ft_putunsigned(nlong / 10);
		if (check_ft_checkformat(pre_value, counter) == -1)
			return (-1);
		pre_value = counter;
		counter += ft_putunsigned(nlong % 10);
		if (check_ft_checkformat(pre_value, counter) == -1)
			return (-1);
	}
	else
	{
		pre_value = counter;
		counter += ft_putchar(nlong + '0');
		if (check_ft_checkformat(pre_value, counter) == -1)
			return (-1);
	}
	return (counter);
}
