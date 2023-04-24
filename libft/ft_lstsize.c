/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:48:47 by vicrodri          #+#    #+#             */
/*   Updated: 2023/04/24 16:33:50 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*La función ft_lstsize devuelve la longitud de la lista enlazada lst.
Si lst es un puntero nulo, devuelve 0.*/