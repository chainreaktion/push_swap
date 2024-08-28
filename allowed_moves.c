/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:55:22 by jschmitz          #+#    #+#             */
/*   Updated: 2024/08/28 18:43:08 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.*/

int	swap_first_elements(t_list **stack)
{
//swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
	t_list *first;
	t_list *second;
	t_list *first_prev;
	t_list *second_next;

	if (stack == NULL || stack->next == NULL)
		return (1);
	first = *stack;
	second = first->next;
	first_prev = first->prev;
	second_next = second->next;
	first->next = second_next;
	second->prev = first_prev;
	first_prev->next = second;
	second_next->prev = first;
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
}

int	push_stack(t_list **stack_a, t_list **stack_b)
{
	//take the first element at the top of b and put it at
	//the top of a. Do nothing if b is empty.
	if (stack_b == NULL)
		return (1);

}
