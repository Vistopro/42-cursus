/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:47:51 by vicrodri          #+#    #+#             */
/*   Updated: 2023/05/24 12:39:50 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_read_buffer(int fd, char *buffer)
{
	int		bread;
	char	*tmp;

	bread = 1;
	tmp = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (bread > 0)
	{
		bread = read(fd, tmp, BUFFER_SIZE);
		if (bread <= 0)
			break ;
		tmp[bread] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(tmp);
	if (bread < 0)
	{
		free (buffer);
		return (0);
	}
	return (buffer);
}

char	*ft_save_buffer(char *str)
{
	char	*buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free (str);
		return (0);
	}
	if (str[i] == '\n')
		i++;
	buffer = ft_calloc(sizeof(char), (ft_strlen(str) - i + 1));
	while (str[i] != '\0')
		buffer[j++] = str[i++];
	buffer[j] = 0;
	free(str);
	return (buffer);
}

char	*ft_fill_line(char *buffer)
{
	int		i;
	char	*result;

	i = 0;
	if (buffer[i] == '\0')
		return (0);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	result = (char *)ft_calloc(sizeof(char), i + 2);
	ft_memcpy(result, buffer, i);
	if (buffer[i] == '\n')
		result[i++] = '\n';
	result[i] = 0;
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer[fd] = ft_read_buffer(fd, buffer[fd]);
	if (!buffer[fd])
	{
		free(buffer[fd]);
		return (0);
	}
	result = ft_fill_line(buffer[fd]);
	buffer[fd] = ft_save_buffer(buffer[fd]);
	return (result);
}

// int main(void)
// {
// 	int fd;
// 	int fd2;
// 	char *buf;

// 	fd = open("hola.txt", O_RDWR);
// 	write(fd, "hola\ncomo\nestas\nAntonio", 23);
// 	close(fd);
// 	fd = open("hola.txt", O_RDWR);

// 	fd2 = open("adios.txt", O_RDWR);
// 	write(fd2, "125\ndsd\n545", 11);
// 	close(fd2);
// 	fd2 = open("adios.txt", O_RDWR);

// 	buf = get_next_line(fd);
// printf("%s", buf);
// buf = get_next_line(fd2);
// 	printf("%s", buf);
// 		buf = get_next_line(fd2);
// printf("%s", buf);
// 		buf = get_next_line(fd2);
// printf("%s", buf);
// 	if (close(fd) == -1)
// 	{
// 		printf("%s\n", "error al cerrar el archivo");
// 		return (1);
// 	}
// 	return (0);
// }