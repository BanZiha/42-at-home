/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:43:57 by hyunwook          #+#    #+#             */
/*   Updated: 2024/05/08 17:15:42 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memfree(char **res)
{
	int	i;

	i = 0;
	while (res[i] != NULL)
	{
		free (res[i]);
		i++;
	}
	free (res);
}

static int	ft_rescount(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static int	ft_resalloc(char const *s, char c, char **res, int i)
{
	int	len;

	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = 0;
			while (*s != c && *s)
			{
				len++;
				s++;
			}
			res[i] = (char *)malloc(sizeof(char) * (len + 1));
			if (res[i] == NULL)
			{
				ft_memfree(res);
				return (0);
			}
			ft_strlcpy((char *)res[i++], (char *)s - len, len + 1);
		}
	}
	res[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	res = (char **)malloc(sizeof(char *) * (ft_rescount(s, c) + 1));
	if (res == NULL)
		return (NULL);
	if (!ft_resalloc(s, c, res, 0))
		return (NULL);
	return (res);
}
