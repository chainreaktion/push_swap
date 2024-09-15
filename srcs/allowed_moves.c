/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:55:22 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/15 11:44:51 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa ou sb
//swap the first 2 elements at the top of the stack.
//Do nothing if there is only one or no elements).
void	swap_first_elements(t_list **stack, t_index *vars, char *move)
{
	t_list	*first;
	t_list	*second;
	t_list	*first_prev;
	t_list	*second_next;

	if (*stack == NULL || (*stack)->next == *stack)
		return ;
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
	move_combo(vars, move);
}

//pa or pb

void	remove_from_a(t_list **stack_a)
{
	t_list	*first_a;
	t_list	*a_prev;
	t_list	*a_next;

	if (*stack_a == NULL)
		return ;
	first_a = *stack_a;
	a_prev = first_a->prev;
	a_next = first_a->next;
	if (first_a->next == first_a)
		*stack_a = NULL;
	else
	{
		a_prev->next = a_next;
		a_next->prev = a_prev;
		*stack_a = a_next;
	}
}

void	add_to_b(t_list **stack_b, t_list *first_a)
{
	t_list	*first_b;
	t_list	*b_prev;

	first_b = *stack_b;
	if (*stack_b == NULL)
	{
		*stack_b = first_a;
		first_a->next = first_a;
		first_a->prev = first_a;
	}
	else
	{
		b_prev = first_b->prev;
		b_prev->next = first_a;
		first_b->prev = first_a;
		first_a->next = first_b;
		first_a->prev = b_prev;
		*stack_b = first_a;
	}
}

void	push_stack(t_list **a, t_list **b, t_index *vars, char *move)
{
	t_list	*first_a;

	if (*a == NULL)
		return ;
	first_a = *a;
	remove_from_a(a);
	add_to_b(b, first_a);
	move_combo(vars, move);
}

/* void	push_stack(t_list **stack_a, t_list **stack_b, t_index *vars, char *move)
{
	t_list	*first_a;
	t_list	*first_b;
	t_list	*a_prev;
	t_list	*a_next;
	t_list	*b_prev;

	if (*stack_a == NULL)
		return ;
	first_a = *stack_a;
	first_b = *stack_b;
	a_prev = first_a->prev;
	a_next = first_a->next;
	//remove first_a from stack_a
	if (first_a->next == first_a)
		*stack_a = NULL;
	else
	{
		a_prev->next = a_next;
		a_next->prev = a_prev;
		*stack_a = a_next;
	}
	if (*stack_b == NULL)
	{
		*stack_b = first_a;
		first_a->next = first_a;
		first_a->prev = first_a;
	}
	else
	{
	//insert first_a at the top of stack_b
		b_prev = first_b->prev;
		b_prev->next = first_a;
		first_b->prev = first_a;
		first_a->next = first_b;
		first_a->prev = b_prev;
	}
	*stack_b = first_a;
	move_combo(vars, move);
} */

//remove first node from stack_a, insert at the top of stack_b
/* void	push_stack(t_list **a, t_list **b, t_index *vars, char *move)
{
	t_list	*a_next;
	t_list	*b_prev;

	if (!(*a))
		return ;
	if ((*a)->next == *a)
		*a = NULL;
	else
	{
		a_next = (*a)->next;
		(*a)->prev->next = a_next;
		a_next->prev = (*a)->prev;
		*a = a_next;
	}
	if (!(*b))
	{
		(edge_case_push_stack(a, b, vars, move));
		return ;
	}
	b_prev = (*b)->prev;
	(*a)->prev = b_prev;
	(*a)->next = *b;
	b_prev->next = *a;
	(*b)->prev = *a;
	*b = *a;
	move_combo(vars, move);
} */
