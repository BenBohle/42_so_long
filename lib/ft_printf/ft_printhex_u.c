/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 06:26:39 by bbohle            #+#    #+#             */
/*   Updated: 2023/12/15 19:46:30 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	assign_printhex_u_helper(unsigned long *tmp, int *counter,
	unsigned int n, int *digits)
{
	*tmp = 0;
	*counter = 0;
	*digits = get_hex_digits(n);
}

int	assign_printhex_u_helper2(int *pre_value, int *counter, int n)
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

int	assign_printhex_u_helper3(int *pre_value, int *counter, unsigned long tmp)
{
	*pre_value = *counter;
	*counter += ft_putchar('0' + tmp);
	if (check_ft_checkformat(*pre_value, *counter) == -1)
		return (-1);
	return (0);
}

int	assign_printhex_u_helper4(int *pre_value, int *counter, unsigned long tmp)
{
	*pre_value = *counter;
	*counter += ft_putchar('A' + tmp - 10);
	if (check_ft_checkformat(*pre_value, *counter) == -1)
		return (-1);
	return (0);
}

int	ft_printhex_u(unsigned int n)
{
	unsigned long	tmp;
	int				counter;
	int				digits;
	int				pre_value;

	assign_printhex_u_helper(&tmp, &counter, n, &digits);
	if (assign_printhex_u_helper2(&pre_value, &counter, n) == -1)
		return (-1);
	while (digits > 0)
	{
		digits--;
		tmp = n >> (digits * 4);
		tmp = tmp & 0xF;
		if (tmp < 10)
		{
			if (assign_printhex_u_helper3(&pre_value, &counter, tmp) == -1)
				return (-1);
		}
		else
		{
			if (assign_printhex_u_helper4(&pre_value, &counter, tmp) == -1)
				return (-1);
		}
	}
	return (counter);
}
