/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:04:47 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/03 22:32:44 by jschmitz         ###   ########.fr       */
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
int	sort_stack_three(stack_a)
{

}
int	sort_stack_five(stack_a)
{

}

int	push_quarter(t_list **stack_a, t_list **stack_b, t_stack **stack_quarter, int list_len)
{
	int	i;
	int	quarter;

	i = 0;
	quarter = list_len \ 4;
	while (i < quarter)
	{
		

	}
}


int	quarter_calculations(t_stack **stack_quarter, t_list **stack_a, list_len)
{
	//defines max and min value of each quarter of the stack
	int	i;
	int	quarter;
	t_list	temp_a;

	i = 0;
	quarter = 0;
	quarter = list_len / 4;
	//even if number is odd, it'll never be more then 3 off
	temp_a = *stack_a;
	stack_quarter->max_value = temp_a->data;
	stack_quarter->min_value = temp_a->data;
	while (i < quarter)
	{
		if (stack_quarter->max_value < temp_a->data)
			stack_quarter->max_value = temp_a->data;
		else if (stack_quarter->min_value > temp_a->data)
			stack_quarter->min_value = temp_a->data;
		temp_a = temp_a->next;
		i++;
	}
	output = push_quarter(stack_a, stack_b, stack_quarter, list_len)



}

int	pick_algorithm(t_list **stack_a, t_list **stack_b int list_len)
{
	int	output;

	if (stack_sorted(stack_a) == 0)
		return (printf("Stack already sorted\n"),0);
	if (list_len = 2)
	{
		if (rotate_stack(stack_a) == 0);
			return (printf("ra\n"), 0);
		else
			return ((printf("Error rotate stack of two\n"), 1));
	}
	else if (list_len == 3)
	{
		if (sort_stack_three(stack_a) == 1)
			return (printf("Error sort stack of three\n"), 1);
		else
			return (0);
	}
	else if (list_len <= 5)
	{


	}
	else
	{
		start_sorting(stack_a, stack_b, list_len);

	}
	return (output);
}
