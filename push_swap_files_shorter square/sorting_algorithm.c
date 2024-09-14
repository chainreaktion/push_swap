/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:04:47 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/10 12:48:25 by jschmitz         ###   ########.fr       */
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

void	sort_stack_three(t_list **stack_a, t_index *chunks)
{
	while (stack_sorted(stack_a) == 1)
	{
		if ((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->data > (*stack_a)->prev->data)
			rotate_stack(stack_a, chunks, "ra\n");
		else if ((*stack_a)->data < (*stack_a)->next->data && (*stack_a)->data > (*stack_a)->prev->data)
			reverse_rotate_stack(stack_a, chunks, "rra\n");
		else if ((*stack_a)->data == (*stack_a)->prev->data)
			reverse_rotate_stack(stack_a, chunks, "rra\n");
		else
			swap_first_elements(stack_a, chunks, "sa\n");
	}
}

void	sort_stack_five(t_list **stack_a, t_list **stack_b, t_index *chunks)
{
	t_list	*temp;

	int		min = 0;
	int		max = 0;

	calc_borders(stack_a, &min, &max);
	temp = *stack_a;
	while (((*stack_a)->next->next->next) != *stack_a)
	{
		if ((temp->data == min) || (temp->data == max))
			push_stack(stack_a, stack_b, chunks, "pb\n");
		temp = temp->next;
	}
	sort_stack_three(stack_a, chunks);
	while ((*stack_b) != NULL)
	{
		if ((*stack_b)->data == min || (*stack_b)->next == (*stack_b))
			push_stack(stack_b, stack_a, chunks, "pa\n");
		else
			rotate_stack(stack_b, chunks, "rb\n");
	}
	if (stack_sorted(stack_a) != 0)
		rotate_stack(stack_a, chunks, "ra\n");
}

void	pick_algorithm(t_list **stack_a, t_list **stack_b, int list_len)
{
	t_index	*chunks;

 //structure"chunks" for sorting
	chunks = (t_index *)malloc(sizeof(t_index));
	if (!chunks)
	{
		printf("Memory allocation chunks failed\n");
		return ;
	}
	chunks->list_len = list_len;
	if (stack_sorted(stack_a) == 0)
		printf("Stack already sorted\n");
	if (list_len == 2)
		rotate_stack(stack_a, chunks, "ra\n");
	else if (list_len == 3)
		sort_stack_three(stack_a, chunks);
	else if (list_len <= 5)
		sort_stack_five(stack_a, stack_b, chunks);
	else
		big_sort(stack_a, stack_b, list_len, chunks);
}
