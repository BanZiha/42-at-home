/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:02:36 by hyunwook          #+#    #+#             */
/*   Updated: 2024/04/26 13:42:25 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (ptr_dst == NULL && ptr_src == NULL)
		return (NULL);
	i = 0;
	if (ptr_dst > ptr_src)
	{
		while (i < len)
		{
			ptr_dst[len - i - 1] = ptr_src[len - i - 1];
			i++;
		}
	}
	else
		ft_memcpy(ptr_dst, ptr_src, len);
	return (dst);
}
