/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-29 20:00:05 by hyunwook          #+#    #+#             */
/*   Updated: 2024-05-29 20:00:05 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_remain(char *remain)
{
	char	*temp;
	char	*update_remain;

	temp = ft_strchr(remain, '\n');
	if (!temp)
	{
		free(remain);
		return (NULL);
	}
	update_remain = (char *)malloc(sizeof(char) * (ft_strlen(temp)));
	if (!update_remain)
	{
		free(remain);
		return (NULL);
	}
	ft_strlcpy(update_remain, temp + 1, ft_strlen(temp));
	free(remain);
	return (update_remain);
}

char	*ft_get_line(char *remain)
{
	char	*line;
	int		i;

	i = 0;
	if (!remain[i])
		return (NULL);
	while (remain[i] && remain[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, remain, i + 2);
	return (line);
}

char	*ft_save_remain(char *buf, char *remain)
{
	char	*temp;

	if (!remain)
		remain = ft_strdup(buf);
	else
	{
		temp = ft_strjoin(remain, buf);
		free(remain);
		remain = temp;
	}
	return (remain);
}

char	*ft_read_fd(int fd, char *remain)
{
	char	*buf;
	int		read_bytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!remain || !ft_strchr(remain, '\n'))
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			free(remain);
			return (NULL);
		}
		if (read_bytes == 0)
			break ;
		buf[read_bytes] = '\0';
		remain = ft_save_remain(buf, remain);
	}
	free(buf);
	return (remain);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	remain = ft_read_fd(fd, remain);
	if (!remain)
		return (NULL);
	line = ft_get_line(remain);
	remain = ft_get_remain(remain);
	return (line);
}
