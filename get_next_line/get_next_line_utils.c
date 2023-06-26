/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:14:34 by vicrodri          #+#    #+#             */
/*   Updated: 2023/05/23 18:33:53 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc(count * size);
	if (s != NULL)
		ft_bzero(s, count * size);
	return (s);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned const char	*str;
	unsigned char		*result;

	i = 0;
	str = (unsigned char *)src;
	result = (unsigned char *)dst;
	if (dst == src || !n)
		return (dst);
	while (i < n)
	{
		result[i] = str[i];
		i++;
	}
	dst = result;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_memcpy(result, s1, ft_strlen(s1));
	ft_memcpy(result + ft_strlen(s1), s2, ft_strlen(s2));
	result[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free((char *)s1);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (((char *)s)[i] != '\0')
	{
		if (((char *)s)[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (((char *)s)[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
