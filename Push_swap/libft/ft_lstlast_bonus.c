/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:04:19 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/26 14:56:02 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La función ft_lstlast devuelve el último elemento de la lista enlazada lst.
Si lst es un puntero nulo, devuelve un puntero nulo.*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*result;

	if (!lst)
		return (0);
	result = lst;
	while (result->next != NULL)
	{
		result = result->next;
	}
	return (result);
}
