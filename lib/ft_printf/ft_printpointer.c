/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:34:07 by bbohle            #+#    #+#             */
/*   Updated: 2023/12/17 03:26:36 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	assign_ft_printpointer_helper(unsigned long *tmp, int *counter,
	unsigned long n, int *digits)
{
	*tmp = 0;
	*counter = 0;
	*digits = get_hex_digits(n);
}

int	assign_ft_printpointer_helper2(int *pre_value, int *counter,
	unsigned long n)
{
	*pre_value = *counter;
	if (n == 0)
	{
		*pre_value = *counter;
		*counter += ft_putchar('0');
		if (check_ft_checkformat(*pre_value, *counter) == -1)
			return (-1);
	}
	return (0);
}

int	assign_ft_printpointer_helper3(int *pre_value, int *counter,
	unsigned long *tmp)
{
	if (*tmp < 10)
	{
		*pre_value = *counter;
		*counter += ft_putchar('0' + *tmp);
		if (check_ft_checkformat(*pre_value, *counter) == -1)
			return (-1);
	}
	else
	{
		*pre_value = *counter;
		*counter += ft_putchar('a' + *tmp - 10);
		if (check_ft_checkformat(*pre_value, *counter) == -1)
			return (-1);
	}
	return (0);
}

int	ft_printpointer(void *p)
{
	unsigned long	tmp;
	unsigned long	n;
	int				counter;
	int				digits;
	int				pre_value;

	n = (unsigned long)p;
	assign_ft_printpointer_helper(&tmp, &counter, n, &digits);
	pre_value = counter;
	counter += ft_putstr("0x");
	if (check_ft_checkformat(pre_value, counter) == -1)
		return (-1);
	if (assign_ft_printpointer_helper2(&pre_value, &counter, n) == -1)
		return (-1);
	while (digits > 0)
	{
		digits--;
		tmp = n >> (digits * 4);
		tmp = tmp & 0xF;
		if (assign_ft_printpointer_helper3(&pre_value, &counter, &tmp) == -1)
			return (-1);
	}
	return (counter);
}
