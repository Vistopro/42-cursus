/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:11:46 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/07 15:22:16 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	absolute_value(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

void	do_move_cost_b(t_stack **stack_a, t_stack **stack_b,
						int cost_a, int cost_b)
{
	while (cost_b != 0)
	{
		if (cost_b > 0)
		{	
			do_rb(stack_b);
			cost_b--;
		}
		else if (cost_b < 0)
		{	
			do_rrb(stack_b);
			cost_b++;
		}
	}
}

void	do_move_cost_c(t_stack **stack_a, t_stack **stack_b,
						int cost_a, int cost_b)
{
	while (cost_a != 0)
	{
		if (cost_a > 0)
		{	
			do_ra(stack_a);
			cost_a--;
		}
		else if (cost_a < 0)
		{	
			do_rra(stack_a);
			cost_a++;
		}
	}
	do_pa(stack_a, stack_b);
}

void	do_move_cost_a(t_stack **stack_a, t_stack **stack_b,
						int cost_a, int cost_b)
{
	while (cost_b != 0 & cost_a != 0)
	{
		if (cost_a > 0 & cost_b > 0)
		{	
			do_rr(stack_a, stack_b);
			cost_a--;
			cost_b--;
		}
		else if (cost_a < 0 & cost_b < 0)
		{	
			do_rrr(stack_a, stack_b);
			cost_a++;
			cost_b++;
		}
		else
			break ;
	}
	do_move_cost_b(stack_a, stack_b, cost_a, cost_b);
	do_move_cost_c(stack_a, stack_b, cost_a, cost_b);
}

void	economic_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		value;
	int		cost_a;
	int		cost_b;

	value = INT_MAX;
	tmp = *stack_b;
	while (tmp)
	{
		if (value > absolute_value(tmp->cost_a) + absolute_value(tmp->cost_b))
		{
			value = absolute_value(tmp->cost_a) + absolute_value(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move_cost_a(stack_a, stack_b, cost_a, cost_b);
}
