/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbohle <bbohle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:04:28 by bbohle            #+#    #+#             */
/*   Updated: 2023/12/15 11:44:30 by bbohle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *input, ...);
void	ft_checkformat(const char *input, int counter, va_list input_args,
			int *printednp);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int n);
int		ft_putchar(char c);
int		ft_printhex_u(unsigned int n);
int		ft_printhex_l(unsigned int n);
int		get_hex_digits(unsigned long n);
int		ft_printpointer(void *p);
int		check_ft_checkformat(int past_printedn, int actual_printedn);

#endif
