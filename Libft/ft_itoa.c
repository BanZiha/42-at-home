/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-02 14:08:31 by hyunwook          #+#    #+#             */
/*   Updated: 2024-05-02 14:08:31 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lencount(int n)
{
	unsigned int	num;
	int				len;

	len = 0;
	if (n < 0)
	{
		num = -1 * n;
		len++;
	}
	else
		num = n;
	if (num == 0)
		len = 1;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static void	ft_recursion(char *res, int len, unsigned int n)
{
	len--;
	if (n >= 10)
		ft_recursion(res, len, n / 10);
	res[len] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = ft_lencount(n);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		ft_recursion(res, len, (unsigned int)(n * -1));
	}
	else
		ft_recursion(res, len, n);
	res[len] = '\0';
	return (res);
}
