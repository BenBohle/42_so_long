/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:00:34 by bbohle            #+#    #+#             */
/*   Updated: 2023/10/31 19:25:03 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start] != '\0' & ft_strrchr(set, s1[start]) != NULL)
	{
		start++;
	}
	return (start);
}

int	ft_end(char const *s1, char const *set)
{
	size_t	end;
	size_t	s1len;

	s1len = ft_strlen(s1);
	end = 0;
	while (end < s1len & ft_strrchr(set, s1[s1len - 1 - end]) != NULL)
	{
		end++;
	}
	return (end);
}

char	*ft_check(size_t start, char *resub, const char *s1, size_t len)
{
	size_t	counter;

	counter = 0;
	while (counter < len)
	{
		resub[counter] = s1[start + counter];
		counter++;
	}
	return (resub);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*resub;

	if (set == NULL || s1 == NULL)
		return (NULL);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	len = ft_strlen(s1) - start - end;
	if (start == (size_t)ft_strlen(s1))
	{
		resub = (char *)malloc(1);
		if (resub == NULL)
			return (NULL);
		resub[0] = '\0';
		return (resub);
	}
	resub = (char *)malloc(len + 1);
	if (resub == NULL)
		return (NULL);
	resub = ft_check(start, resub, s1, len);
	resub[len] = '\0';
	return (resub);
}
