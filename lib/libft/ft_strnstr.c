/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:03:45 by bbohle            #+#    #+#             */
/*   Updated: 2023/10/26 22:55:13 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	findlen;
	size_t	counter;

	findlen = ft_strlen(find);
	counter = 0;
	if (findlen == 0)
	{
		return ((char *)str);
	}
	if ((len < findlen && str != NULL) || *str == '\0')
	{
		return (NULL);
	}
	while (counter <= len - findlen)
	{
		if (ft_strncmp(&str[counter], find, findlen) == 0)
		{
			return ((char *)&str[counter]);
		}
		counter++;
	}
	return (NULL);
}
