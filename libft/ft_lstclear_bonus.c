/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:03:26 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/26 14:55:32 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La función ft_lstclear elimina y libera la memoria de todos los 
elementos de la lista enlazada lst, utilizando la función 'del' 
para liberar la memoria de cada elemento.
Finalmente, establece el puntero lst en un puntero nulo.*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (*lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = temp;
		}
		*lst = NULL;
	}
}
