/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:04:47 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/12 00:24:55 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TOO MANY FUNCTIONS
//returns 1 if not sorted and 0 if sorted
int	stack_sorted(t_list **stack)
{
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

void	sort_stack_three(t_list **stack_a, t_index *vars)
{
	while (stack_sorted(stack_a) == 1)
	{
		if ((*stack_a)->data > (*stack_a)->next->data
			&& (*stack_a)->data > (*stack_a)->prev->data)
		{
			rotate_stack(stack_a, vars, "ra\n");
		}
		else if ((*stack_a)->data < (*stack_a)->next->data
			&& (*stack_a)->data > (*stack_a)->prev->data)
		{
			reverse_rotate_stack(stack_a, vars, "rra\n");
		}
		else if ((*stack_a)->data == (*stack_a)->prev->data)
		{
			reverse_rotate_stack(stack_a, vars, "rra\n");
		}
		else
		{
			swap_first_elements(stack_a, vars, "sa\n");
		}
	}
}

void	sort_stack_five(t_list **stack_a, t_list **stack_b, t_index *chunks)
{
	t_list	*temp;
	int		min;
	int		max;

	min = 0;
	max = 0;
	calc_borders(stack_a, &min, &max);
	temp = *stack_a;
	while ((*stack_a)->next->next->next != *stack_a)
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
	t_index	*vars;

 //structure"chunks" for sorting
	vars = (t_index *)malloc(sizeof(t_index));
	if (!vars)
	{
		printf("Memory allocation vars failed\n");
		return ;
	}
	index_ini(&vars);
	vars->list_len = list_len;
	//printf("list_len = %d\n", vars->list_len);
	if (stack_sorted(stack_a) == 0)
		return ;
	if (list_len == 2)
		rotate_stack(stack_a, vars, "ra\n");
	else if (list_len == 3)
		sort_stack_three(stack_a, vars);
	else if (list_len <= 5)
		sort_stack_five(stack_a, stack_b, vars);
	else
		big_sort(stack_a, stack_b, vars);
}
