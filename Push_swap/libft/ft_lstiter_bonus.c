/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:04:03 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/26 14:55:49 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La función ft_lstiter itera sobre los elementos de la lista enlazada 
lst y aplica la función 'f' a cada elemento.
La función f toma un puntero al contenido del elemento como argumento.*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
