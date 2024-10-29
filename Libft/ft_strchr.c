/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-25 15:47:12 by hyunwook          #+#    #+#             */
/*   Updated: 2024-04-25 15:47:12 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ptr_s;

	ptr_s = (char *)s;
	i = 0;
	while (ptr_s[i])
	{
		if (ptr_s[i] == (char)c)
			return (&ptr_s[i]);
		i++;
	}
	if (ptr_s[i] == (char)c)
		return (&ptr_s[i]);
	return (NULL);
}
