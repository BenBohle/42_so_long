/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:08:37 by bbohle            #+#    #+#             */
/*   Updated: 2023/11/13 15:34:18 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*resub;
	size_t	slen;

	resub = NULL;
	slen = ft_strlen(s);
	if (slen < start || s == NULL)
	{
		return (ft_strdup(""));
	}
	if (slen < start + len)
	{
		len = slen - start;
	}
	resub = (char *)ft_calloc(1, len + 1);
	if (resub == NULL)
	{
		return (NULL);
	}
	ft_memcpy(resub, s + start, len);
	return (resub);
}
