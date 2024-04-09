/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:15:24 by bbohle            #+#    #+#             */
/*   Updated: 2023/11/10 18:49:42 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char		*destcv;
	size_t		counter;
	const char	*srccv;

	destcv = dest;
	srccv = src;
	counter = 0;
	if (destcv == srccv)
	{
		return (dest);
	}
	while (counter < size)
	{
		destcv[counter] = srccv[counter];
		counter++;
	}
	return (dest);
}
