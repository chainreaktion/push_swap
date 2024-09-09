/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:19:34 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/06 17:57:39 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_borders(t_list **stack_a, int *min, int *max)
{
	t_list	*temp;

//	printf("Entered calc borders\n");
	temp = *stack_a;
	*min = temp->data;
	*max = temp->data;
	while (temp->next != *stack_a)
	{
		if (temp->data > *max)
		{
			*max = temp->data;
		}
		else if (temp->data < *min)
		{
			*min = temp->data;
		}
		temp = temp->next;
	}
}

//receives stack_a and pointers to the min and max value
/* void	calc_borders(t_list **stack_a)
{
	//not sure about the booleans...
	t_list	*temp;

	printf("Entered calc borders\n");

	temp = *stack_a;
	temp->min = temp->data;
	temp->max = temp->data;
	while (temp->next != *stack_a)
	{
		if (temp->data > temp->max)
		{
			temp->max = temp->data;
			temp->max = true;
		}
		else if (temp->data < temp->min)
		{
			temp->min = temp->data;
			temp->min = true;
		}
		temp = temp->next;
	}
	if (temp->data > temp->max)
	{
		temp->max = temp->data;
		temp->max = true;
	}
	else if (temp->data < temp->min)
	{
		temp->min = temp->data;
		temp->min = true;
	}
	temp = temp->next;
	printf("Max=%d, Min=%d\n", temp->max, temp->min);
} */
/*
int	calc_push_cost(t_list **stack_a, )
{


} */
