/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:15:38 by bbohle            #+#    #+#             */
/*   Updated: 2023/10/23 18:16:16 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t n)
{
	unsigned int			counter;
	register unsigned char	*up;

	up = (unsigned char *)str;
	counter = 0;
	while (n > counter)
	{
		up[counter] = value;
		counter++;
	}
	return (str);
}
