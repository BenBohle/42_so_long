/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:10:03 by bbohle            #+#    #+#             */
/*   Updated: 2023/11/10 18:49:54 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	int					counter;
	const unsigned char	*strcv;
	unsigned char		ccv;

	strcv = str;
	ccv = (unsigned char)c;
	counter = 0;
	while (counter < (int)n)
	{
		if (strcv[counter] == ccv)
		{
			return ((void *)(strcv + counter));
		}
		counter++;
	}
	return (0);
}
