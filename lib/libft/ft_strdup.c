/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:05:30 by bbohle            #+#    #+#             */
/*   Updated: 2023/10/28 20:30:25 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s) + 1;
	s2 = (char *)malloc(len);
	if (s2 == NULL)
	{
		return (NULL);
	}
	ft_memcpy(s2, s, len);
	return (s2);
}
