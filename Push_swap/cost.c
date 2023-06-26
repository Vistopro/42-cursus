/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:21:05 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/06 15:28:35 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	calc_cost_a(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = ft_stack_size(stack);
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->pos <= i / 2)
			tmp->cost_a = tmp->pos;
		else
			tmp->cost_a = -(i - tmp->pos);
		tmp = tmp->next;
	}
}

void	calc_cost_b(t_stack *b, t_stack *a)
{
	t_stack	*tmp_b;
	int		i;
	int		j;

	i = ft_stack_size(b);
	j = ft_stack_size(a);
	tmp_b = b;
	while (tmp_b != NULL)
	{
		if (tmp_b->pos <= i / 2)
			tmp_b->cost_b = tmp_b->pos;
		else
			tmp_b->cost_b = -(i - tmp_b->pos);
		if (tmp_b->target_pos <= j / 2)
		{
			tmp_b->cost_a = (tmp_b->target_pos);
		}
		else
			tmp_b->cost_a = -(j - tmp_b->target_pos);
		tmp_b = tmp_b->next;
	}
}
