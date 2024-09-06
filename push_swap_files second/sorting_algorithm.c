/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:04:47 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/05 14:54:08 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* size_t	cost_calculator()
{
	size_t	cost;


	return (cost);
} */

int		stack_sorted(t_list **stack)
{
	t_list	*temp;
	t_list	*next_node;

	temp = *stack;
	next_node = temp->next;
/* 	if (temp->data > next_node->data)
		return (1);
	temp = temp->next;
	next_node = temp->next; */
	while (next_node != *stack)
	{
		if (temp->data > next_node->data)
			return (1);
		temp = temp->next;
		next_node = temp->next;
	}
	return (0);
}

int	sort_stack_three(t_list **stack_a)
{
	printf("Entered sort_stack_three\n");
	while (stack_sorted(stack_a) == 1)
	{
		if ((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->data > (*stack_a)->prev->data)
		{
			rotate_stack(stack_a);
			printf("ra\n");
		}
		else if ((*stack_a)->data < (*stack_a)->next->data && (*stack_a)->data > (*stack_a)->prev->data)
		{
			reverse_rotate_stack(stack_a);
			printf("rra\n");
		}
		else if ((*stack_a)->data == (*stack_a)->prev->data)
		{
			reverse_rotate_stack(stack_a);
			printf("rra\n");
		}
		else
		{
			swap_first_elements(stack_a);
			printf("sa\n");
		}
/* 		first = *stack_a;
		if (first->data > first->next->data && first->data > first->prev->data)
		{
			rotate_stack(stack_a);
			printf("ra\n");
		}
		else if (first->data < first->next->data && first->data > first->prev->data)
		{
			reverse_rotate_stack(stack_a);
			printf("rra\n");
		}
		else if (first->data == first->prev->data)
		{
			reverse_rotate_stack(stack_a);
			printf("rra\n");
		}
		else
		{
			swap_first_elements(stack_a);
			printf("sa\n");
		} */
	}
	return (0);
}
/* int	sort_stack_five(stack_a)
{

} */

int	pick_algorithm(t_list **stack_a, t_list **stack_b, int list_len)
{
	int	output = 0;

	printf("Entered pick_algorithm\n");
	(void)stack_b;
	if (stack_sorted(stack_a) == 0)
		return (printf("Stack already sorted\n"),0);
	if (list_len == 2)
	{
		//if (rotate_stack(stack_a) == 0)
		rotate_stack(stack_a);
		return (printf("ra\n"), 0);
		/* else
			return ((printf("Error rotate stack of two\n"), 1)); */
	}
	else if (list_len == 3)
	{
	/* 	if (sort_stack_three(stack_a) == 1)
			return (printf("Error sort stack of three\n"), 1);
		else
			return (0); */
		sort_stack_three(stack_a);
	}
	else if (list_len <= 5)
	{
		printf("for 5 not yet coded\n");
	}
	else
	{
		start_sorting(stack_a, stack_b, list_len);
		printf("Rest not yet coded\n");
	}
	return (output);
}
