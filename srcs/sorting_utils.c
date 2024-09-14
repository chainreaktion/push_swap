/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:19:34 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/14 16:20:19 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_borders(t_list **stack_a, int *min, int *max)
{
	t_list	*temp;

	temp = *stack_a;
	*min = temp->data;
	*max = temp->data;
	while (1)
	{
		if (temp->data > *max)
		{
			*max = temp->data;
		}
		else if (temp->data < *min)
		{
			*min = temp->data;
		}
		if (temp->next == *stack_a)
			break ;
		temp = temp->next;
	}
}

int	circ_list_len(t_list **stack)
{
	t_list	*temp;
	int		len;

	if (*stack == NULL)
		return (0);
	temp = *stack;
	len = 0;
	while (temp->next != *stack)
	{
		temp = temp->next;
		len++;
	}
	len++;
	return (len);
}

int	calc_chunk_size(t_list **stack, int min, int max)
{
	int		res;
	t_list	*temp;

	res = 0;
	temp = *stack;
	while (1)
	{
		if (temp->data >= min && temp->data < max)
			res++;
		temp = temp->next;
		if (temp == *stack)
			break ;
	}
	return (res);
}

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

int	count_elem(t_list **stack, int n)
{
	int		res;
	t_list	*temp;

	res = 0;
	temp = *stack;
	while (temp)
	{
		if (temp->chunk == n)
			res++;
		temp = temp->next;
		if (temp == *stack)
			break ;
	}
	return (res);
}
