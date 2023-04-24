/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:33:46 by vicrodri          #+#    #+#             */
/*   Updated: 2023/04/24 15:39:57 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}

/*La función ft_lstdelone elimina y libera la memoria de un elemento 
de la lista enlazada lst, utilizando la función 'del' para 
liberar la memoria del contenido del elemento.
Finalmente, establece el puntero lst en un puntero nulo.*/