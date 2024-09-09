/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:19:34 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/09 20:40:59 by jschmitz         ###   ########.fr       */
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

/* int	calc_push_cost(t_list **stack_a, )
{


}  */
