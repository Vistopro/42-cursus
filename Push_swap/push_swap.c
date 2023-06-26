/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:43:04 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/07 14:58:53 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	check_sort(t_stack *a)
{
	while (a->next != NULL)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	calc_pos(t_stack **a, t_stack **b)
{
	init_pos(*a);
	init_pos(*b);
	init_target_pos(a, b);
	calc_cost_a(*a);
	calc_cost_b(*b, *a);
	economic_cost(a, b);
}

void	order_more_three(t_stack **a, t_stack **b, int i, int n)
{
	i = 0;
	while (ft_stack_size(*a) > 3)
	{
		if ((*a)->index - i <= (n / 2))
			do_pb(a, b);
		else if ((*a)->index - i > (n / 2))
		{
			do_ra(a);
			i++;
		}
	}
	sort_three(a);
	while ((*b) != NULL)
		calc_pos(a, b);
	init_pos(*a);
	while ((*a)->index != (*a)->pos +1)
	{
		if ((*a)->pos >= ft_stack_size(*a) / 2)
			do_ra(a);
		else if ((*a)->pos < ft_stack_size(*a) / 2)
			do_rra(a);
		init_pos(*a);
	}
}

void	push_swap(char **argv, int argc)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		n;

	i = 0;
	a = NULL;
	b = NULL;
	if (argc == 2)
		i = -1;
	while (argv[++i] != NULL)
	{
		n = ft_atoi(argv[i]);
		ft_stack_add_back(&a, stack_new((int)n));
	}
	n = ft_stack_size(a);
	init_index(a, n + 1);
	if (n == 2 & check_sort(a) == 0)
		do_sa(a);
	else if (n == 3 & check_sort(a) == 0)
		sort_three(&a);
	else if (n > 3 & check_sort(a) == 0)
		order_more_three(&a, &b, i, n);
	free_stack(&a);
	free_stack(&b);
}
