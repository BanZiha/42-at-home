/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:09:24 by hyunwook          #+#    #+#             */
/*   Updated: 2024/05/28 14:31:24 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		len += ft_putunbr(-n);
	}
	else
		len += ft_putunbr(n);
	return (len);
}
