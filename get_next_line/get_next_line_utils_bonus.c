/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-05 16:19:38 by hyunwook          #+#    #+#             */
/*   Updated: 2024-06-05 16:19:38 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		i++;
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[j] = s2[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;

	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	i = 0;
	while ((i < (dstsize - 1)) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}
