/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:15:49 by bbohle            #+#    #+#             */
/*   Updated: 2024/02/01 17:29:20 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *destination, char *source, size_t size)
{
	size_t	counter;
	size_t	srclen;

	counter = 0;
	srclen = 0;
	if (size > 0)
	{
		while (source[counter] != '\0' && counter < size - 1)
		{
			destination[counter] = source[counter];
			counter++;
		}
		destination[counter] = '\0';
	}
	srclen = ft_strlen(source);
	return (srclen);
}
