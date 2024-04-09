/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:36:21 by bbohle            #+#    #+#             */
/*   Updated: 2024/03/06 19:35:07 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int in)
{
	char	ia;
	char	*tmp;

	ia = in;
	tmp = NULL;
	while (1)
	{
		if (*str == ia)
		{
			tmp = (char *)str;
		}
		if (*str == '\0' && tmp <= 0)
		{
			return (NULL);
		}
		if (*str == '\0' && tmp > 0)
		{
			return (tmp);
		}
		str++;
	}
}
