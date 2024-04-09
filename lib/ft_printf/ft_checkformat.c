/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:13:47 by bbohle            #+#    #+#             */
/*   Updated: 2023/12/15 20:11:22 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_hex_digits(unsigned long n)
{
	int				digits;
	unsigned long	tmp;

	tmp = n;
	digits = 0;
	while (tmp != 0)
	{
		tmp /= 16;
		digits++;
	}
	return (digits);
}

void	ft_checkformat(const char *input, int counter, va_list input_args,
		int *printednp)
{
	int	tmpcounter;

	tmpcounter = 0;
	if (input[counter] == 'c')
		*printednp += ft_putchar(va_arg(input_args, int));
	else if (input[counter] == 's')
		*printednp += ft_putstr(va_arg(input_args, char *));
	else if (input[counter] == 'p')
	{
		*printednp += ft_printpointer(va_arg(input_args, void *));
	}
	else if (input[counter] == 'd' || input[counter] == 'i')
		*printednp += ft_putnbr(va_arg(input_args, int));
	else if (input[counter] == 'u')
		*printednp += ft_putunsigned(va_arg(input_args, unsigned int));
	else if (input[counter] == 'x')
		*printednp += ft_printhex_l(va_arg(input_args, unsigned long));
	else if (input[counter] == 'X')
		*printednp += ft_printhex_u(va_arg(input_args, unsigned long));
	else if (input[counter] == '%')
		*printednp += ft_putchar('%');
}
