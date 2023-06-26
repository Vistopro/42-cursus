/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:05:00 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/26 14:56:39 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La función ft_lstsize devuelve la longitud de la lista enlazada lst.
Si lst es un puntero nulo, devuelve 0.*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*temp;

	size = 0;
	if (!lst)
		return (0);
	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
		size++;
	}
	size++;
	return (size);
}
