/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:33:06 by vicrodri          #+#    #+#             */
/*   Updated: 2023/04/20 18:00:17 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Utilizando malloc(3), genera una string que represente el valor entero 
recibido como argumento. Los números negativos tienen que gestionarse.*/

#include "libft.h"
#include <stdio.h>

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

int	ft_lenint(int n)
{
	size_t			i;
	unsigned int	np;

	i = 0;
	np = 0;
	if (n < 0)
	{
		np = n * (-1);
		i++;
	}
	else
	{
		np = n;
	}
	while (np > 0)
	{
		i++;
		np = np / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*result;
	unsigned int	np;

	np = 0;
	i = ft_lenint(n);
	result = malloc(i + 1);
    if (!result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		np = n * (-1);
	}
	else
		np = n;
    if (n == 0)
    {
        result[i]=0 + '0';
        return result;
    }
	ft_bzero(result + i, i);
	while (np > 0)
	{
		result[i - 1] = np % 10 + '0';
		np = np / 10;
		i--;
	}
	return (result);
}

int	main(void)
{
	int n = 0;
	char *result;
	result = ft_itoa(n);
	
	printf("%s", result);
}