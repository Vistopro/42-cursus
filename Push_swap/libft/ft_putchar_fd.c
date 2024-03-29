/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:22:45 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/26 14:57:47 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Envía el carácter ’c’ al file descriptor especificado.*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	char	c;
// 	char	*a;

// 	int fd, sz;
// 	c = 'a';
// 	a = (char *)calloc(100, sizeof(char));
// 	fd = open("hola.txt", O_RDWR);
// 	ft_putchar_fd(c, fd);
// 	sz = read(fd, a, 2);
// 	printf("It returned %s\n", a);
// 	a[sz] = '\0';
// 	int close(int fd);
// }
