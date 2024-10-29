/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-24 15:09:05 by hyunwook          #+#    #+#             */
/*   Updated: 2024-04-24 15:09:05 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr_b;
	unsigned char	char_c;

	ptr_b = (unsigned char *)b;
	char_c = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ptr_b[i] = char_c;
		i++;
	}
	return (b);
}
