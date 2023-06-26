/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:45:14 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/06 15:28:16 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = ft_stack_last(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = ft_stack_last(*stack);
	before_tail = ft_stack_before_last(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	tmp = *stack_1;
	*stack_1 = (*stack_1)->next;
	tmp->next = *stack_2;
	*stack_2 = tmp;
}

void	sort_three(t_stack **a)
{
	if ((*a)->value > (*a)->next->value
		& (*a)->value > (*a)->next->next->value)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	else if ((*a)->next->value > (*a)->value
		& (*a)->next->value > (*a)->next->next->value)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	if ((*a)->value > (*a)->next->value)
	{
		swap(*a);
		write(1, "sa\n", 3);
	}
}
