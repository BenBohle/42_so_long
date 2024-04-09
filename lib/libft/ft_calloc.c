/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:40:08 by bbohle            #+#    #+#             */
/*   Updated: 2023/11/13 15:25:58 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	ts;
	void	*p;
	size_t	counter;

	ts = 0;
	p = NULL;
	counter = 0;
	if (nitems == 0 || size == 0)
	{
		return (malloc(0));
	}
	ts = nitems * size;
	p = malloc(ts);
	if (p != NULL)
	{
		while (counter < ts)
		{
			((char *)p)[counter] = 0;
			counter++;
		}
	}
	return (p);
}
