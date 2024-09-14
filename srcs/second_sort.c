/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:17:55 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/14 16:22:00 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//naive version for first try
void	push_max_or_min(t_list **stack_a, t_list **stack_b, t_index *vars, int max)
{
	int	cost_r_max;
	int	cost_rr_max;

	//printf("enter push max or min\n");
	/* while (count_elem(stack_b, n) > 0)
	{ */
	cost_r_max = calc_cost_r_max(stack_b, max);
	cost_rr_max = calc_cost_rr_max(stack_b, max);
	//printf("cost_r_max = %d\n cost_rr_max = %d\n", cost_r_max, cost_rr_max);
	if (cost_r_max < cost_rr_max)
	{
		while (cost_r_max > 0)
		{
			rotate_stack(stack_b, vars, "rb\n");
			//printf("Aftr move, value on top = %d\n", (*stack_b)->data);
			//reverse_rotate_stack(stack_b, vars, "rrb\n");
			cost_r_max--;
		}
	}
	else
	{
		while (cost_rr_max > 0)
		{
			//rotate_stack(stack_b, vars, "rb\n");
			//printf("Aftr move, value on top = %d\n", (*stack_b)->data);
			reverse_rotate_stack(stack_b, vars, "rrb\n");
			cost_rr_max--;
		}
	}
	push_stack(stack_b, stack_a, vars, "pa\n");
}

void	empty_chunk(t_list **stack_a, t_list ** stack_b, t_index *vars, int n)
{
	int	min;
	int	max;
	int	elem_in_chunk;

	min = 0;
	max = 0;
	calc_borders(stack_b, &min, &max);
	elem_in_chunk = calc_chunk_size(stack_b, vars->levers[n - 1], max);
	while (elem_in_chunk > 0)
	{
		calc_borders(stack_b, &min, &max);
		push_max_or_min(stack_a, stack_b, vars, max);
		elem_in_chunk--;
	}
}

void	push_all_back(t_list **stack_a, t_list **stack_b, t_index *vars)
{
	int	n;

	n = vars->chunk_num;
	while (n > 0)
	{
		empty_chunk(stack_a, stack_b, vars, n);
		n--;
	}
	push_stack(stack_b, stack_a, vars, "pa\n");
}
