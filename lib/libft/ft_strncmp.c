/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:07:43 by bbohle            #+#    #+#             */
/*   Updated: 2023/10/26 21:09:31 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0 && (*str1 != '\0' || *str2 != '\0'))
	{
		if (*str1 != *str2)
		{
			return ((unsigned char)*str1 - (unsigned char)*str2);
		}
		str1++;
		str2++;
		n--;
	}
	return (0);
}
