/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:34:53 by bbohle            #+#    #+#             */
/*   Updated: 2023/11/10 18:49:49 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	int					counter;
	const unsigned char	*str1cv;
	const unsigned char	*str2cv;

	str1cv = str1;
	str2cv = str2;
	counter = 0;
	while (counter < (int)n)
	{
		if (str1cv[counter] != str2cv[counter])
		{
			return (str1cv[counter] - str2cv[counter]);
		}
		counter++;
	}
	return (0);
}
