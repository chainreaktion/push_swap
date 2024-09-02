/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:04:47 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/02 22:10:11 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	cost_calculator()
{
	size_t	cost;


	return (cost);
}

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

int	calculate_median()
{


}

int	pick_algorithm(t_list **stack_a, size_t list_len)
{
	int	output;

	if (stack_sorted(stack_a) == 0)
		return (0);
	if (list_len <= 2)
	{
		rotate_stack(stack_a);
		printf("ra\n");
	}
	else if (list_len == 3)
	{
		if 
	}
	else if (list_len <= 5)
	{


	}
	else
	{


	}
	return (output);
}
