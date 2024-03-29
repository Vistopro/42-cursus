/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:09:56 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/26 14:54:30 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The isdigit() function tests for a decimal digit character.The value of the 
argument must be representable as an unsigned char or the value of EOF.

The	isdigit(void) afunction return zero if the character tests
false and return non-zero if the character tests true.*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*int	main(void)
{
	int c = 51;
	printf("%d\n", isdigit(c));
	printf("%d\n", ft_isdigit(c));
}*/
