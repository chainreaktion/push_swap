/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:55:22 by jschmitz          #+#    #+#             */
/*   Updated: 2024/08/30 22:35:48 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_first_elements(t_list **stack)
{
//swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
	t_list *first;
	t_list *second;
	t_list *first_prev;
	t_list *second_next;

	if (*stack == NULL || (*stack)->next == *stack)
		return (1);
	first = *stack;
	second = first->next;
	first_prev = first->prev;
	second_next = second->next;

	first->next = second_next;
	second->prev = first_prev;

	first_prev->next = second;
	second_next->prev = first;

	second->next = first;
	first->prev = second;

	*stack = second;
	return (0);
}

int swap_a_and_b(t_list **stack_a, t_list **stack_b)
{
	//ss : sa and sb at the same time.
	if (swap_first_elements(stack_a) == 0
		&& swap_first_elements(stack_b) == 0)
		return (0);
	else
		return (1);
// if either of he swaps fails, returns 1
//(eg if one of the stacks is empty)
}

int	push_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	t_list	*first_b;
	t_list	*first_a_prev;
	t_list	*first_a_next;
	t_list	*first_b_prev;
	t_list	*first_b_next;

//take the first element at the top of b and put it at
//the top of a. Do nothing if b is empty.
	if (*stack_b == NULL)
		return (1);
//Get first nodes of each stack
	first_a = *stack_a;
	first_b = *stack_b;
// Get the surrounding nodes
	first_a_prev = first_a->prev;
	first_a_next = first_a->next;
	first_b_prev = first_b->prev;
	first_b_next = first_b->next;
// Link the nodes
	first_a_prev->next = first_b;
	first_a_next->prev = first_b;

	first_b_prev->next = first_a;
	first_b_next->prev = first_a;

	first_b->next = first_a_next;
	first_b->prev = first_a_prev;

	first_a->next = first_b_next;
	first_a->prev = first_b_prev;

	*stack_a = first_b;
	*stack_b = first_a;
	return (0);
}

void	rotate_stack(t_list **stack)
{
	*stack = (*stack)->next;
}

void	rotate_both_stacks(t_list **stack_a, t_list **stack_b)
{
	*stack_a = (*stack_a)->next;
	*stack_b = (*stack_b)->next;
}

void	reverse_rotate_stack(t_list **stack)
{
	*stack = (*stack)->prev;
}

void	reverse_rotate_both_stacks(t_list **stack_a, t_list **stack_b)
{
	*stack_a = (*stack_a)->prev;
	*stack_b = (*stack_b)->prev;
}
