/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:44:21 by bbohle            #+#    #+#             */
/*   Updated: 2024/03/06 19:08:43 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int in)
{
	char	ia;

	ia = in;
	while (1)
	{
		if (*string == '\0' && ia != '\0')
		{
			return (NULL);
		}
		if (*string == ia)
		{
			return ((char *)string);
		}
		string++;
	}
}
