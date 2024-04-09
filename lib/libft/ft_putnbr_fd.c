/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:59:03 by bbohle            #+#    #+#             */
/*   Updated: 2023/11/10 17:19:13 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int long		nlong;

	nlong = n;
	if (nlong < 0)
	{
		nlong *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nlong >= 10)
	{
		ft_putnbr_fd(nlong / 10, fd);
		ft_putnbr_fd(nlong % 10, fd);
	}
	else
	{
		ft_putchar_fd(nlong + '0', fd);
	}
}
