/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:55:22 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/06 17:45:13 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//sa ou sb
void	swap_first_elements(t_list **stack, char stack_name)
{
//swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
	t_list *first;
	t_list *second;
	t_list *first_prev;
	t_list *second_next;

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
	//c is the case when
	if (stack_name != 'c')
		printf("s%c\n", stack_name);
	return ;
}

//ss = sa & sb
void	swap_a_and_b(t_list **stack_a, t_list **stack_b)
{
	//ss : sa and sb at the same time.
	swap_first_elements(stack_a, 'c');
	swap_first_elements(stack_b, 'c');
	printf("ss\n");
}

//TOO LONG
void	push_stack(t_list **stack_a, t_list **stack_b, char stack_name)
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
	printf("p%c\n", stack_name);
}

void	rotate_stack(t_list **stack, char stack_name)
{
	*stack = (*stack)->next;
	printf("r%c\n", stack_name);
}

void	rotate_both_stacks(t_list **stack_a, t_list **stack_b)
{
	*stack_a = (*stack_a)->next;
	*stack_b = (*stack_b)->next;
	printf("rr\n");
}

void	reverse_rotate_stack(t_list **stack, char stack_name)
{
	*stack = (*stack)->prev;
	printf("rr%c\n", stack_name);
}

void	reverse_rotate_both_stacks(t_list **stack_a, t_list **stack_b)
{
	*stack_a = (*stack_a)->prev;
	*stack_b = (*stack_b)->prev;
	printf("rrr\n");
}