/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:17:42 by vicrodri          #+#    #+#             */
/*   Updated: 2023/06/07 14:16:00 by vicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;
void	push_swap(char **argv, int argc);
void	swap(t_stack *a);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	ft_stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_new(int n);
t_stack	*ft_stack_last(t_stack *stack);
t_stack	*ft_stack_before_last(t_stack *stack);
int		ft_stack_size(t_stack *stack);
void	init_index(t_stack *stack_a, int stack_size);
void	push(t_stack **stack_1, t_stack **stack_2);
void	sort_three(t_stack **a);
void	init_pos(t_stack *stack);
void	init_target_pos(t_stack **stack_a, t_stack **stack_b);
void	calc_cost_a(t_stack *stack);
void	calc_cost_b(t_stack *b, t_stack *a);
t_stack	*ft_stack_before_last(t_stack *stack);
void	economic_cost(t_stack **stack_a, t_stack **stack_b);
void	free_stack(t_stack **stack);
int		absolute_value(int num);
void	calc_cost_a(t_stack *stack);
void	calc_cost_b(t_stack *b, t_stack *a);
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_sa(t_stack *stack_a);

#endif