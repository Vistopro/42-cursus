/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:27:52 by vicrodri          #+#    #+#             */
/*   Updated: 2023/04/24 14:34:30 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}

// int	main(void)
// {
// 	char	*content;
// 	t_list	*result;

// 	content = "hola";
// 	result = ft_lstnew(content);
// 	printf("%s\n", result->content);
// }

/*Crea un nuevo nodo utilizando malloc(3). La variable miembro ’content’ se
inicializa con el contenido del parámetro ’content’. La variable
’next’, con NULL.*/