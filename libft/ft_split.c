/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:06:30 by vicrodri          #+#    #+#             */
/*   Updated: 2023/04/24 16:34:46 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>

int	ft_strcont(char const *s, char c)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c && i != 0)
			n++;
		i++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		nwords;
	int		i;
	int		len;

	i = 0;
	len = 0;
	nwords = 0;
	result = (char **)malloc(sizeof(char **) * (ft_strcont(s, c) + 1));
	if (!result)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
			len++;
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c && i != 0)
		{
			result[nwords] = ft_calloc(len + 1, 1);
			result[nwords] = (ft_memmove(result[nwords], &s[i - len + 1], len));
			result[nwords++][len] = '\0';
			len = 0;
		}
		i++;
	}
	return (result[nwords] = NULL, result);
}

// int	main(void)
// {
// 	char	*s;
// 	char	c;
// 	char **result;

// 	s = "hola a todo s";
// 	c = ' ';
// 	result = ft_split(s, c);
// 	printf("%s\n", result[0]);
// 	printf("%s\n", result[1]);
// 	printf("%s\n", result[2]);
// 	printf("%s\n", result[3]);
// 	printf("%s\n", result[4]);
// 	printf("%s\n", result[5]);
// 	printf("%s\n", result[6]);
// 	printf("%s\n", result[7]);
// 	printf("%s\n", result[8]);
// 	printf("%s\n", result[9]);
// 	printf("%s\n", result[10]);
// 	printf("%s\n", result[11]);

// }

/*Reserva (utilizando malloc(3)) un array de strings resultante de separar la
string ’s’ en substrings utilizando el caracter ’c’ como delimitador. El
array debe terminar con un puntero NULL.*/