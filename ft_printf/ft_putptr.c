/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:40:46 by hyunwook          #+#    #+#             */
/*   Updated: 2024/05/27 18:18:45 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	else
		len += ft_putstr("0x");
	if (ptr >= 16)
	{
		len += ft_puthex(ptr / 16, 'x');
		len += ft_puthex(ptr % 16, 'x');
	}
	else
	{
		if (ptr < 10)
			len += ft_putchar(ptr + '0');
		else
			len += ft_putchar(ptr - 10 + 'a');
	}
	return (len);
}
