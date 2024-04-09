/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:15:31 by bbohle            #+#    #+#             */
/*   Updated: 2023/11/13 14:59:15 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*check1(size_t size, char *tmp, const char *srctmp, void *dest)
{
	int	counter;

	counter = size - 1;
	while (counter >= 0)
	{
		tmp[counter] = srctmp[counter];
		counter--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	int			counter;
	char		*tmp;
	const char	*srctmp;

	tmp = dest;
	srctmp = src;
	counter = 0;
	if (tmp == srctmp || size == 0)
		return (dest);
	if (tmp > srctmp && (tmp - srctmp) < (int)size)
	{
		return (check1(size, tmp, srctmp, dest));
	}
	if (tmp < srctmp && (srctmp - tmp) < (int)size)
	{
		while (counter != (int)size)
		{
			tmp[counter] = srctmp[counter];
			counter++;
		}
		return (dest);
	}
	ft_memcpy(dest, src, size);
	return (dest);
}
