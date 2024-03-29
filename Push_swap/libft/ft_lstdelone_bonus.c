/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:03:45 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/26 14:55:40 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La función ft_lstdelone elimina y libera la memoria de un elemento 
de la lista enlazada lst, utilizando la función 'del' para 
liberar la memoria del contenido del elemento.
Finalmente, establece el puntero lst en un puntero nulo.*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}
