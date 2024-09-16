/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:17:55 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/16 03:25:47 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//naive version for first try
void	push_max_or_min(t_list **a, t_list **b, t_index *vars, int max)
{
	int		cost_r_max;
	int		cost_rr_max;

	cost_r_max = calc_cost_r_max(b, max);
	cost_rr_max = calc_cost_rr_max(b, max);
	if (cost_r_max < cost_rr_max)
	{
		while (cost_r_max > 0)
		{
			rotate_stack(b, vars, "rb\n");
			cost_r_max--;
		}
	}
	else
	{
		while (cost_rr_max > 0)
		{
			reverse_rotate_stack(b, vars, "rrb\n");
			cost_rr_max--;
		}
	}
	push_stack(b, a, vars, "pa\n");
}

void	empty_chunk(t_list **a, t_list **b, t_index *vars, int n)
{
	int	min;
	int	max;
	int	elem_in_chunk;

	min = 0;
	max = 0;
	calc_borders(b, &min, &max);
	elem_in_chunk = calc_chunk_size(b, vars->levers[n - 1], max);
	while (elem_in_chunk >= 0)
	{
		calc_borders(b, &min, &max);
		push_max_or_min(a, b, vars, max);
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
}
