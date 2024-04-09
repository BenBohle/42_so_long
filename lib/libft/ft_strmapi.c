/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:42:58 by bbohle            #+#    #+#             */
/*   Updated: 2023/11/03 16:57:53 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	counter;
	char			*resub;

	counter = 0;
	len = ft_strlen(s);
	if (s == NULL && f == NULL)
	{
		return (NULL);
	}
	resub = (char *)malloc(len + 1);
	if (resub == NULL)
	{
		return (NULL);
	}
	while (counter < len)
	{
		resub[counter] = f(counter, s[counter]);
		counter++;
	}
	resub[len] = '\0';
	return (resub);
}
