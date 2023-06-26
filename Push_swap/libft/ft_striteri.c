/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:24:00 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/26 14:59:10 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*A cada carácter de la string ’s’, aplica la función ’f’ dando como parámetros
el índice de cada carácter dentro de ’s’ y la dirección del propio
carácter, que podrá modificarse si es necesario.*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// void	f(unsigned int i, char *c)
// {
//     c[i] ='0';
// }

// int	main(void)
// {
// 	char	*s;

// 	s = "hola";
//     ft_striteri(s, *f);
// 	printf("%s", s);
// }
