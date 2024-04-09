/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:58:17 by bbohle            #+#    #+#             */
/*   Updated: 2023/11/03 17:05:08 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			len;
	unsigned int	counter;

	counter = 0;
	len = ft_strlen(s);
	while (counter < len)
	{
		f(counter, &s[counter]);
		counter++;
	}
}
