/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:13:47 by bbohle            #+#    #+#             */
/*   Updated: 2023/12/15 17:24:37 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list	input_args;
	int		counter;
	int		printedn;
	int		temp_printedn;

	counter = 0;
	printedn = 0;
	va_start(input_args, input);
	while (input[counter] != '\0')
	{
		temp_printedn = printedn;
		if (input[counter] == '%' && input[counter + 1] != '\0')
		{
			counter++;
			ft_checkformat(input, counter, input_args, &printedn);
		}
		else
			printedn += ft_putchar(input[counter]);
		counter++;
		if (check_ft_checkformat(temp_printedn, printedn) == -1)
			return (-1);
	}
	va_end(input_args);
	return (printedn);
}
