/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:05:29 by vicrodri          #+#    #+#             */
/*   Updated: 2023/04/24 16:33:43 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;

	result = 0;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, temp);
		lst = lst->next;
	}
	return (result);
}

/*La función ft_lstmap crea una nueva lista enlazada mediante la aplicación de 
la función f a cada elemento de la lista lst.
Si ocurre un error durante la creación de la nueva lista, se llama a 
la función del para liberar la memoria de todos los elementos de la lista.
Finalmente, devuelve un puntero a la nueva lista enlazada.*/