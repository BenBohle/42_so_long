/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:11:17 by bbohle            #+#    #+#             */
/*   Updated: 2023/10/26 19:39:55 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	counter;
	size_t	dlen;
	size_t	slen;

	counter = 0;
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (size <= dlen)
	{
		return (size + slen);
	}
	if (dest != NULL && src != NULL)
	{
		while ((src[counter] != '\0') && (counter < size - dlen - 1))
		{
			dest[dlen + counter] = src[counter];
			counter++;
		}
		dest[dlen + counter] = '\0';
		return (dlen + slen);
	}
	return (dlen + slen);
}
