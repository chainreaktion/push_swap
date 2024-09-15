/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:06:29 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/15 11:44:47 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ra or rb
void	rotate_stack(t_list **stack, t_index *vars, char *move)
{
	*stack = (*stack)->next;
	move_combo(vars, move);
}

//rra or rrb
void	reverse_rotate_stack(t_list **stack, t_index *vars, char *move)
{
	*stack = (*stack)->prev;
	move_combo(vars, move);
}

/* //ss = sa & sb
void	swap_a_and_b(t_list **stack_a, t_list **stack_b)
{
	swap_first_elements(stack_a);
	swap_first_elements(stack_b);
}

//rr
void	rotate_both_stacks(t_list **stack_a, t_list **stack_b)
{
	*stack_a = (*stack_a)->next;
	*stack_b = (*stack_b)->next;
}


//rrr
void	reverse_rotate_both_stacks(t_list **stack_a, t_list **stack_b)
{
	*stack_a = (*stack_a)->prev;
	*stack_b = (*stack_b)->prev;
} */
