/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwook <hyunwook@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-05 12:06:34 by hyunwook          #+#    #+#             */
/*   Updated: 2024-06-05 12:06:34 by hyunwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd);
char	*ft_read_and_save(int fd, char *remain);
char	*ft_get_line(char *remain);
char	*ft_get_remain(char *remain);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

int main(void)
{
	int fd;
	char *line;

	fd = open("test1.txt", O_RDONLY);
	// while ((line = get_next_line(fd)))
	// {
	// 	printf("%s", line);
	// 	free(line);
	// }
	line = get_next_line(fd);
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -o get_next_line get_next_line.c get_next_line_utils.c main.c
// ./get_next_line

// #include <unistd.h>
// #include <stdio.h>

// int main() {
//     long max_fd = sysconf(_SC_OPEN_MAX);
//     printf("Maximum number of file descriptors: %ld\n", max_fd);
//     return 0;
// }
