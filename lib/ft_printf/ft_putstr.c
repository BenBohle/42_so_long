/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:07:46 by bbohle            #+#    #+#             */
/*   Updated: 2023/12/17 03:24:25 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	counter;

	counter = 0;
	if (s == NULL)
	{
		s = "(null)";
	}
	while (s[counter] != '\0')
	{
		if (write(1, &s[counter], 1) == -1)
			return (-1);
		counter++;
	}
	return (counter);
}
