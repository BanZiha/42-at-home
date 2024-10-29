/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:41:12 by hyunwook          #+#    #+#             */
/*   Updated: 2024/05/28 11:30:30 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long n, char c)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_puthex(n / 16, c);
		len += ft_puthex(n % 16, c);
	}
	else
	{
		if (n < 10)
			len += ft_putchar(n + '0');
		else
		{
			if (c == 'x')
				len += ft_putchar(n - 10 + 'a');
			else
				len += ft_putchar(n - 10 + 'A');
		}
	}
	return (len);
}
