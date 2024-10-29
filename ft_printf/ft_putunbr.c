/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:09:39 by hyunwook          #+#    #+#             */
/*   Updated: 2024/05/28 11:30:54 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putunbr(n / 10);
		len += ft_putunbr(n % 10);
	}
	else
		len += ft_putchar(n + '0');
	return (len);
}
