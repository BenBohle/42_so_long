/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 04:32:29 by bbohle            #+#    #+#             */
/*   Updated: 2023/11/14 16:23:32 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wcount(const char *s, char c)
{
	size_t	w;
	size_t	containswords;

	containswords = 0;
	w = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			if (containswords)
			{
				containswords = 0;
			}
		}
		else
		{
			if (!containswords)
			{
				w++;
				containswords = 1;
			}
		}
		s++;
	}
	return (w);
}

void	*free_resub(char **resub)
{
	int	counter;

	counter = 0;
	while (resub[counter] != NULL)
	{
		free(resub[counter]);
		counter++;
	}
	free(resub);
	return (NULL);
}

const char	*p1(const char *s, int c)
{
	const char	*start;

	start = NULL;
	while (*s == c)
	{
		s++;
	}
	start = s;
	return (start);
}

char	**get_resub(const char *s, char **resub, char c, size_t wcount)
{
	size_t		subcounter;
	size_t		counter;
	const char	*start;

	counter = 0;
	start = NULL;
	while (counter < wcount)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		resub[counter] = (char *)malloc((s - start + 1) * sizeof(char));
		if (resub[counter] == NULL)
			return (free_resub(resub));
		subcounter = 0;
		while (subcounter < (size_t)(s - start))
		{
			resub[counter][subcounter] = start[subcounter];
			subcounter++;
		}
		resub[counter++][s - start] = '\0';
	}
	return (resub);
}

char	**ft_split(const char *s, char c)
{
	char	**resub;
	size_t	wcount;

	wcount = ft_wcount(s, c);
	resub = (char **)malloc((wcount + 1) * sizeof(char *));
	if (resub == NULL)
		return (NULL);
	resub = get_resub(s, resub, c, wcount);
	if (resub == NULL)
		return (NULL);
	resub[wcount] = NULL;
	return (resub);
}
