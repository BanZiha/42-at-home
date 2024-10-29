/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-15 20:30:36 by hyunwook          #+#    #+#             */
/*   Updated: 2024-05-15 20:30:36 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_check_format(va_list *ap, const char *format);
int		ft_putchar(char c);
int		ft_putptr(unsigned long long ptr);
int		ft_puthex(unsigned long long n, char c);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_putstr(char *s);

#endif