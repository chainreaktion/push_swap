/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:04:47 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/14 21:19:54 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_three(t_list **stack_a, t_index *vars)
{
	int	current;
	int	last;
	int	next_num;

	while (stack_sorted(stack_a) == 1)
	{
		current = (*stack_a)->data;
		last = (*stack_a)->prev->data;
		next_num = (*stack_a)->next->data;
		if (current > next_num && current > last)
			rotate_stack(stack_a, vars, "ra\n");
		else if (current < next_num && current > last)
			reverse_rotate_stack(stack_a, vars, "rra\n");
		else
			swap_first_elements(stack_a, vars, "sa\n");
	}
}

void	sort_stack_five(t_list **stack_a, t_list **stack_b, t_index *vars)
{
	t_list	*temp;
	int		min;
	int		max;

	min = 0;
	max = 0;
	calc_borders(stack_a, &min, &max);
	temp = *stack_a;
	while (((*stack_a)->next->next->next) != *stack_a)
	{
		if ((temp->data == min) || (temp->data == max))
			push_stack(stack_a, stack_b, vars, "pb\n");
		temp = temp->next;
	}
	sort_stack_three(stack_a, vars);
	while ((*stack_b) != NULL)
	{
		if ((*stack_b)->data == min || (*stack_b)->next == (*stack_b))
			push_stack(stack_b, stack_a, vars, "pa\n");
		else
			rotate_stack(stack_b, vars, "rb\n");
	}
	if (stack_sorted(stack_a) != 0)
		rotate_stack(stack_a, vars, "ra\n");
}

void	big_sort(t_list **stack_a, t_list **stack_b, int list_len, t_index *vars)
{
	int		chunk_num;

	chunk_num = ft_sqrt(list_len);
	initialize_array(vars, chunk_num);
	vars->chunk_num = chunk_num;
	iterate_all_levers(stack_a, vars, vars->chunk_num);
	make_chunks(stack_a, stack_b, vars, vars->chunk_num);
	push_all_back(stack_a, stack_b, vars);
}

void	pick_algorithm(t_list **stack_a, t_list **stack_b, t_index *vars)
{
	int	list_len;

	list_len = vars->list_len;
	if (stack_sorted(stack_a) == 0)
		return ;
	if (list_len == 2)
		rotate_stack(stack_a, vars, "ra\n");
	else if (list_len == 3)
		sort_stack_three(stack_a, vars);
	else if (list_len <= 5)
		sort_stack_five(stack_a, stack_b, vars);
	else
		big_sort(stack_a, stack_b, list_len, vars);
}
