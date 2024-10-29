/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-25 16:06:12 by hyunwook          #+#    #+#             */
/*   Updated: 2024-04-25 16:06:12 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ptr_s;

	ptr_s = (char *)s;
	i = ft_strlen(s);
	if ((char)c == '\0')
		return (&ptr_s[i]);
	while (i > 0)
	{
		if (ptr_s[i - 1] == (char)c)
			return (&ptr_s[i - 1]);
		i--;
	}
	return (NULL);
}
