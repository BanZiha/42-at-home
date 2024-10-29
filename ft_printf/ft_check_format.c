/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:53:45 by hyunwook          #+#    #+#             */
/*   Updated: 2024/05/28 12:08:17 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(va_list *ap, const char *format)
{
	int	len;

	len = 0;
	if (*format == 'c')
		len += ft_putchar(va_arg(*ap, int));
	else if (*format == 's')
		len += ft_putstr(va_arg(*ap, char *));
	else if (*format == 'p')
		len += ft_putptr(va_arg(*ap, unsigned long long));
	else if (*format == 'd' || *format == 'i')
		len += ft_putnbr(va_arg(*ap, int));
	else if (*format == 'u')
		len += ft_putunbr(va_arg(*ap, unsigned int));
	else if (*format == 'x' || *format == 'X')
		len += ft_puthex(va_arg(*ap, unsigned int), *format);
	else if (*format == '%')
		len += ft_putchar('%');
	return (len);
}
