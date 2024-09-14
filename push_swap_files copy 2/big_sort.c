/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:23:42 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/12 00:28:28 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_chunk_size(t_list **stack, int min, int max)
{
	int		res;
	t_list	*temp;

	res = 0;
	temp = *stack;
	while (1)
	{
		if (temp->data >= min && temp->data <= max)
			res++;
		temp = temp->next;
		if (temp == *stack)
			break ;
	}
	return (res);
}

//if chunk is smaller than it should be  > increase lever
//if chunk is bigger than it should be > decrease lever
int	adjust_lever(t_list **stack_a, int *min, int *max_rel, int *goal)
{
	int	chunk_size;

	chunk_size = calc_chunk_size(stack_a, *min, *max_rel);
	if (chunk_size == *goal)
		return (*max_rel);
	else if (chunk_size > *goal)
	{
		(*max_rel)--;
		return (adjust_lever(stack_a, min, max_rel, goal));
	}
	else
	{
		(*max_rel)++;
		return (adjust_lever(stack_a, min, max_rel, goal));
	}
}

void	iterate_all_levers(t_list **stack_a, t_index *vars, int goal)
{
	int	n;

	initialize_array(vars);
	//calculate and add min and max to the array
	calc_borders(stack_a, &(vars->levers[0]), &(vars->levers[goal]));
	vars->max_value = vars->levers[goal];
	n = 1;
	while (n < goal)
	{
		//avoid going over the maximum input value
		if ((vars->levers[n - 1] + goal) >= vars->levers[goal])
			vars->levers[n] = vars->levers[goal] - 1;
		//naively set next lever to former lever + ideal chunk-size
		else
			vars->levers[n] = vars->levers[n - 1] + goal;
		//adjusting lever so that the number of elements contained is correct
		adjust_lever(stack_a, &(vars->levers[n - 1]), &(vars->levers[n]), &goal);
		n++;
	}
}

//lever = int array with min (lever[0]), lever1 (lever[1]),
//lever2 (lever[2]) and max (lever[3])
//goal is the size half the pile should have when the lever is correct
void	iterate_levers(t_list **stack_a, t_index *vars)
{
	int		ter_siz;
	int		list_len;

	//calculate and add min and max to the array
	calc_borders(stack_a, &(vars->levers[0]), &(vars->levers[3]));
	vars->max_value = vars->levers[3];
	//calculate the optimal tercile size
	//list_len = circ_list_len(stack_a);
	ter_siz = vars->list_len / 3;
	vars->ter_siz[0] = ter_siz;
	vars->ter_siz[2] = ter_siz;
	vars->ter_siz[1] = ter_siz + (vars->list_len % 3);
	//printf("Tercil size: 1 %d, 2 %d, 3 %d\n", vars->ter_siz[0], vars->ter_siz[1], vars->ter_siz[2]);
	//naively set next lever to former lever + ideal tercile-size
	vars->levers[1] = vars->levers[0] + vars->ter_siz[0];
	vars->levers[2] = vars->levers[1] + vars->ter_siz[2];
	//printf("Levers before: min %d, l1 %d, l2 %d, max%d\n", vars->levers[0], vars->levers[1], vars->levers[2], vars->levers[3]);
	//adjusting levers so that the number of elements contained is correct
	adjust_tercil_max(stack_a, &(vars->levers[0]), &(vars->levers[1]), ter_siz);
	adjust_tercil_min(stack_a, &(vars->levers[2]), &(vars->levers[3]), ter_siz);
	//printf("Levers after: min %d, l1 %d, l2 %d, max%d\n", vars->levers[0], vars->levers[1], vars->levers[2], vars->levers[3]);

}

void	push_to_b(t_list **stack_a, t_list **stack_b, t_index *vars, int n)
{
//never push the max value
	if ((*stack_a)->data == vars->max_value)
		rotate_stack(stack_a, vars, "ra\n");
//case if value is between min and lever
	if ((*stack_a)->data >= vars->levers[n - 1] && (*stack_a)->data <= vars->levers[n])
	{
//case if this is the first push to b, no rotation needed
		if (*stack_b == NULL)
			push_stack(stack_a, stack_b, vars, "pb\n");
		else
		{
			push_stack(stack_a, stack_b, vars, "pb\n");
			rotate_stack(stack_b, vars, "rb\n");
		}
	}
//case if value is between max and lever
	else if ((*stack_a)->data > vars->levers[n] && (*stack_a)->data < vars->levers[n + 1])
		push_stack(stack_a, stack_b, vars, "pb\n");
//if the node is not in the current chunk, put it to the bottom of stack a for now
	else
		rotate_stack(stack_a, vars, "ra\n");
}

//adds two chunks above and below the existing in stack_b
void	create_two_chunks(t_list **stack_a, t_list **stack_b, t_index *vars, int n)
{
	t_list	*temp;
	t_list	*last_node;

	temp = *stack_a;
	last_node = temp->prev;
	while (temp != last_node)
	{
		push_to_b(stack_a, stack_b, vars, n);
		temp = *stack_a;
	}
	push_to_b(stack_a, stack_b, vars, n);
}

//push a-values to b according to the chunks
int	make_chunks(t_list **stack_a, t_list **stack_b, t_index *chunks, int goal)
{
	int	n;

	n = 1;
	while (n < goal)
	{
		create_two_chunks(stack_a, stack_b, chunks, n);
		n += 2;
	}
	//push to b until only max value is left in a
	while ((*stack_a)->next != *stack_a)
	{
		if ((*stack_a)->data == chunks->levers[goal])
			rotate_stack(stack_a, chunks, "ra\n");
		else
			push_stack(stack_a, stack_b, chunks, "pb\n");
	}
	return (n);
}

int	count_elem(t_list **stack, int n)
{
	int		res;
	t_list	*temp;

	res = 0;
	temp = *stack;
	while (temp->next != *stack)
	{
		if (temp->ter == n)
		res++;
	}
	return (res);
}

void	big_sort(t_list **stack_a, t_list **stack_b, t_index *vars)
{
	int	n;

	vars->chunk_num = ft_sqrt(vars->list_len);
	n = 1;
	iterate_all_levers(stack_a, vars, vars->chunk_num);
	n = make_chunks(stack_a, stack_b, vars, vars->chunk_num);
	free (vars);
}
