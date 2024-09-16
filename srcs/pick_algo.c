/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:04:47 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/16 13:15:26 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_three(t_list **stack_a, t_index *vars)
{
	t_list	*temp;
	int		min;
	int		max;

	temp = *stack_a;
	while (stack_sorted(&temp) == 1)
	{
		calc_borders(&temp, &min, &max);
		if (temp->data == max)
			rotate_stack(stack_a, vars, "ra\n");
		else if (temp->prev->data == min)
			reverse_rotate_stack(stack_a, vars, "rra\n");
		else
			swap_first_elements(stack_a, vars, "sa\n");
		temp = *stack_a;
	}
}

void	sort_stack_four(t_list **stack_a, t_list **stack_b, t_index *vars)
{
	int		min;
	int		max;

	calc_borders(stack_a, &min, &max);
	while ((*stack_a)->data != min)
	{
		if ((*stack_a)->next->data == min)
			rotate_stack(stack_a, vars, "ra\n");
		else
			reverse_rotate_stack(stack_a, vars, "rra\n");
	}
	push_stack(stack_a, stack_b, vars, "pb\n");
	sort_stack_three(stack_a, vars);
	push_stack(stack_b, stack_a, vars, "pa\n");
	move_combo(vars, NULL);
}

void	sort_stack_five(t_list **stack_a, t_list **stack_b, t_index *vars)
{
	int		min;
	int		max;

	calc_borders(stack_a, &min, &max);
	while (circ_list_len(stack_a) > 3)
	{
		if (((*stack_a)->data == min) || ((*stack_a)->data == max))
			push_stack(stack_a, stack_b, vars, "pb\n");
		else
			rotate_stack(stack_a, vars, "ra\n");
	}
	sort_stack_three(stack_a, vars);
	if ((*stack_b)->data == max)
		rotate_stack(stack_b, vars, "rb\n");
	push_stack(stack_b, stack_a, vars, "pa\n");
	push_stack(stack_b, stack_a, vars, "pa\n");
	if ((*stack_a)->prev->data == min)
		rotate_stack(stack_a, vars, "ra\n");
	if ((*stack_a)->data == max)
		rotate_stack(stack_a, vars, "ra\n");
	move_combo(vars, NULL);
}

/* void	sort_stack_five(t_list **stack_a, t_list **stack_b, t_index *vars)
{
	int		min;
	int		max;

	calc_borders(stack_a, &min, &max);
	while (circ_list_len(stack_a) > 3)
	{
		if (((*stack_a)->data == min) || ((*stack_a)->data == max))
			push_stack(stack_a, stack_b, vars, "pb\n");
		else
			rotate_stack(stack_a, vars, "ra\n");
	}
	sort_stack_three(stack_a, vars);
	if ((*stack_b)->data == min)
		push_stack(stack_b, stack_a, vars, "pa\n");
	else
	{
		if ((*stack_b)->next != *stack_b)
			rotate_stack(stack_b, vars, "rb\n");
		push_stack(stack_b, stack_a, vars, "pa\n");
	}
	push_stack(stack_b, stack_a, vars, "pa\n");
	if (stack_sorted(stack_a) == 1)
		rotate_stack(stack_a, vars, "ra\n");
	move_combo(vars, NULL);
} */

void	big_sort(t_list **a, t_list **b, int list_len, t_index *vars)
{
	int		chunk_num;

	chunk_num = ft_sqrt(list_len);
	initialize_array(vars, chunk_num);
	vars->chunk_num = chunk_num;
	iterate_all_levers(a, vars, vars->chunk_num);
	make_chunks(a, b, vars, vars->chunk_num);
	push_all_back(a, b, vars);
}

void	pick_algorithm(t_list **stack_a, t_list **stack_b, t_index *vars)
{
	int	list_len;

	list_len = vars->list_len;
	if (stack_sorted(stack_a) == 0)
		return ;
	if (list_len == 2)
	{
		rotate_stack(stack_a, vars, "ra\n");
		move_combo(vars, NULL);
	}
	else if (list_len == 3)
	{
		sort_stack_three(stack_a, vars);
		move_combo(vars, NULL);
	}
	else if (list_len == 4)
		sort_stack_four(stack_a, stack_b, vars);
	else if (list_len == 5)
		sort_stack_five(stack_a, stack_b, vars);
	else
		big_sort(stack_a, stack_b, list_len, vars);
}
