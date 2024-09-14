/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:18:34 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/14 16:19:04 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_cost_r_max(t_list **stack_b, int max)
{
	t_list	*temp;
	int		res;

	temp = *stack_b;
	res = 0;
	while (temp->data != max)
	{
		temp = temp->next;
		res++;
	}
	return (res);
}

int	calc_cost_rr_max(t_list **stack_b, int max)
{
	t_list	*temp;
	int		res;

	temp = *stack_b;
	res = 0;
	while (temp->data != max)
	{
		temp = temp->prev;
		res++;
	}
	return (res);
}
