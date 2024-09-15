/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:23:42 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/15 23:13:34 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//if chunk is smaller than it should be  > increase max
//if chunk is bigger than it should be > decrease max
//goal is the size the chunk should have when the lever is set correctly
int	adjust_lever(t_list **stack_a, t_index *vars, int min, int max_rel)
{
	int	chunk_size;
	int	goal;

	goal = vars->chunk_num;
	if (vars->list_len % vars->chunk_num != 0)
		goal--;
	chunk_size = calc_chunk_size(stack_a, min, max_rel);
	if (chunk_size == goal)
		return (max_rel);
	else if (chunk_size > goal)
	{
		max_rel--;
		return (adjust_lever(stack_a, vars, min, max_rel));
	}
	else
	{
		max_rel++;
		return (adjust_lever(stack_a, vars, min, max_rel));
	}
}

//max = chunk_num and index of the max lever
//naively set next lever to former lever + ideal chunk-size
//avoid going over the maximum value
//adjusting lever so that the number of elements contained is correct
void	iterate_all_levers(t_list **stack_a, t_index *vars, int max)
{
	int	lev;
	int	estim;
	int	min;

	calc_borders(stack_a, &(vars->levers[0]), &(vars->levers[max]));
	vars->max_value = vars->levers[max];
	lev = 1;
	while (lev < max)
	{
		estim = vars->max_value / vars->chunk_num;
		vars->levers[lev] = vars->levers[lev - 1] + estim;
		if (vars->levers[lev] >= vars->max_value)
			vars->levers[lev] = vars->max_value - 1;
		min = vars->levers[lev - 1];
		vars->levers[lev] = adjust_lever(stack_a, vars, min, vars->levers[lev]);
		lev++;
	}
}

//lev = the lever between the two chunks that are being pushed
	//if the node is not in the current chunk, put it to the bottom of stack a for now

void	push_to_b(t_list **a, t_list **b, t_index *v, int lev)
{
	if ((*a)->data >= v->levers[lev - 1] && (*a)->data < v->levers[lev])
	{
		(*a)->chunk = lev;
		(*a)->ind = -1;
		if (*b == NULL)
			push_stack(a, b, v, "pb\n");
		else
		{
			push_stack(a, b, v, "pb\n");
			rotate_stack(b, v, "rb\n");
		}
	}
	else if ((*a)->data >= v->levers[lev] && (*a)->data < v->levers[lev + 1])
	{
		(*a)->chunk = lev + 1;
		(*a)->ind = 1;
		push_stack(a, b, v, "pb\n");
	}
	else
		rotate_stack(a, v, "ra\n");
}

//lev = the lever between the two chunks that are being pushed
void	create_two_chunks(t_list **a, t_list **b, t_index *vars, int lev)
{
	int	i;

	i = 0;
	i = circ_list_len(a);
	while (i > 0)
	{
		if ((*a)->data == vars->max_value)
			rotate_stack(a, vars, "ra\n");
		else
			push_to_b(a, b, vars, lev);
		i--;
	}
}

//push a-values to b according to the chunks
//goal = total number of chunks
//create two chunks for every second lever-value
void	make_chunks(t_list **a, t_list **b, t_index *vars, int goal)
{
	int		lev;
	int		pairs;

	lev = 1;
	pairs = goal;
	if (goal % 2 != 0)
		pairs--;
	while (lev < pairs)
	{
		create_two_chunks(a, b, vars, lev);
		lev += 2;
	}
	while ((*a)->next != *a)
	{
		(*a)->chunk = lev;
		if ((*a)->data == vars->max_value)
			rotate_stack(a, vars, "ra\n");
		else
		{
			(*a)->ind = 1;
			push_stack(a, b, vars, "pb\n");
		}
	}
}
