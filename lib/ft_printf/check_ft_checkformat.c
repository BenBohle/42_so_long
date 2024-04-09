/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ft_checkformat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:54:28 by bbohle            #+#    #+#             */
/*   Updated: 2023/12/15 11:46:08 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_ft_checkformat(int past_printedn, int actual_printedn)
{
	if (past_printedn > actual_printedn)
	{
		return (-1);
	}
	return (0);
}
