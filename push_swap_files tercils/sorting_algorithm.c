/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:04:47 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/07 17:57:58 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TOO MANY FUNCTIONS
int	stack_sorted(t_list **stack)
{
	//returns 1 if not sorted and 0 if sorted
	t_list	*temp;
	t_list	*next_node;

	temp = *stack;
	next_node = temp->next;
	while (next_node != *stack)
	{
		if (temp->data > next_node->data)
			return (1);
		temp = temp->next;
		next_node = temp->next;
	}
	return (0);
}

void	sort_stack_three(t_list **stack_a)
{
//	printf("Entered sort_stack_three\n");
	while (stack_sorted(stack_a) == 1)
	{
		if ((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->data > (*stack_a)->prev->data)
		{
			rotate_stack(stack_a, 'a');
		}
		else if ((*stack_a)->data < (*stack_a)->next->data && (*stack_a)->data > (*stack_a)->prev->data)
		{
			reverse_rotate_stack(stack_a, 'a');
		}
		else if ((*stack_a)->data == (*stack_a)->prev->data)
		{
			reverse_rotate_stack(stack_a, 'a');
		}
		else
		{
			swap_first_elements(stack_a, 'a');
		}
	}
}

void	sort_stack_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	int		min = 0;
	int		max = 0;

	//printf("Entered sort stack five\n");
	calc_borders(stack_a, &min, &max);
//	printf("Max=%d, Min=%d\n", max, min);
	temp = *stack_a;
	while (((*stack_a)->next->next->next) != *stack_a)
	{
	//	printf("Entered while loop\n");
		if ((temp->data == min) || (temp->data == max))
		{
			//printf("Entered if condition\n");
			push_stack(stack_a, stack_b, 'b');
			//print_stack(*stack_a);
		}
		temp = temp->next;
	}
	//print_stack(*stack_a);
	sort_stack_three(stack_a);
	while ((*stack_b) != NULL)
	{
		if ((*stack_b)->data == min || (*stack_b)->next == (*stack_b))
			push_stack(stack_b, stack_a, 'a');
		else
			rotate_stack(stack_b, 'b');
	}
	if (stack_sorted(stack_a) != 0)
		rotate_stack(stack_a, 'a');
}

void	pick_algorithm(t_list **stack_a, t_list **stack_b, int list_len)
{
//	printf("Entered pick_algorithm\n");
//	(void)stack_b;
	if (stack_sorted(stack_a) == 0)
		printf("Stack already sorted\n");
	if (list_len == 2)
		rotate_stack(stack_a, 'a');
	else if (list_len == 3)
		sort_stack_three(stack_a);
	else if (list_len <= 5)
		sort_stack_five(stack_a, stack_b);
	else
	{
		//big_sort(stack_a, stack_b, list_len);
		//big_sort(stack_a, stack_b);
		big_sort(stack_a, stack_b, list_len);
		printf("Rest not yet coded\n");
	}
}
