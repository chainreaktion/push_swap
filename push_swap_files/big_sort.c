/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:23:42 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/14 02:18:40 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_chunk_size(t_list **stack, int min, int max)
{
	int		res;
	t_list	*temp;

	res = 0;
	temp = *stack;
//	dprintf(2, "SUCCESS");
	while (1)
	{
		if (temp->data >= min && temp->data < max)
			res++;
		temp = temp->next;
		if (temp == *stack)
			break ;
	}
	//printf("chunk-size = %d\n", res);
	return (res);
}

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
	//printf("CHUNK SIZE:%d\nGoal:%d min:%d max:%d\n\n", chunk_size, goal, min, max_rel);
	//sleep(1);
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
void	iterate_all_levers(t_list **stack_a, t_index *vars, int max)
{
	int	lev;
	int	estim;

	//calculate and add min and max to the array
	calc_borders(stack_a, &(vars->levers[0]), &(vars->levers[max]));
	vars->max_value = vars->levers[max];
	lev = 1;
	//printf("Min = %d\n", vars->levers[0]);
	//printf("Max = %d\n", vars->levers[max]);
	//if (vars->chunk_num % 2 != 0)
	//	new_max = vars->chunk_num - 1;
	while (lev < max)
	{
		//avoid going over the maximum input value
		estim = vars->max_value / vars->chunk_num;
		vars->levers[lev] = vars->levers[lev - 1] + estim;
		if (vars->levers[lev] >= vars->max_value)
			vars->levers[lev] = vars->max_value - 1;
		//naively set next lever to former lever + ideal chunk-size
		//else
		//vars->levers[lev] = vars->levers[lev - 1] + new_max;

	//	vars->levers[lev] = vars->levers[lev - 1] + vars->chunk_num;

		//adjusting lever so that the number of elements contained is correct
		//adjust_lever(stack_a, &(vars->levers[lev - 1]), &(vars->levers[lev]), new_max);
		//printf("Lev = %d\n", lev);
		vars->levers[lev] = adjust_lever(stack_a, vars, vars->levers[lev - 1], vars->levers[lev]);
		//printf("New lever = %d\n", vars->levers[lev]);
		lev++;
	}
/* 	lev = 1;
	printf("Chunk_num: %d\n", vars->chunk_num);
	printf("Min: %d\n", vars->levers[0]);
	while (lev < max)
	{
		printf("Lever %d: %d\n", lev, vars->levers[lev]);
		lev++;
	}
	printf("Max: %d\n", vars->levers[max]); */
}

void	initialize_array(t_index *vars, int chunk_num)
{
	int	i;

	i = 0;
	vars->levers = malloc(sizeof(int) * (chunk_num + 1));
	if (!vars->levers)
	{
		printf("Memory allocation levers failed\n");
		free(vars);
		exit (0);
	}
	while (i < vars->chunk_num + 1)
	{
		vars->levers[i] = 0;
		i++;
	}
}

//lev = the lever between the two chunks that are being pushed
void	push_to_b(t_list **stack_a, t_list **stack_b, t_index *vars, int lev)
{
	//printf("Lev = %d\nLever = %d\n", lev, vars->levers[lev]);
	//case if value is between min and current lever
	if ((*stack_a)->data >= vars->levers[lev - 1] && (*stack_a)->data < vars->levers[lev])
	{
		(*stack_a)->chunk = lev;
		(*stack_a)->ind = -1;
		//case if this is the first push to b, no rotation needed
		if (*stack_b == NULL)
			push_stack(stack_a, stack_b, vars, "pb\n");
		else
		{
			push_stack(stack_a, stack_b, vars, "pb\n");
			rotate_stack(stack_b, vars, "rb\n");
		}
	}
	//case if value is between max and current lever
	else if ((*stack_a)->data >= vars->levers[lev] && (*stack_a)->data < vars->levers[lev + 1])
	{
		(*stack_a)->chunk = lev + 1;
		(*stack_a)->ind = 1;
		push_stack(stack_a, stack_b, vars, "pb\n");
	}
	//if the node is not in the current chunk, put it to the bottom of stack a for now
	else
		rotate_stack(stack_a, vars, "ra\n");
}

//lev = the lever between the two chunks that are being pushed
void	create_two_chunks(t_list **stack_a, t_list **stack_b, t_index *vars, int lev)
{
	int i = 0;

	i = circ_list_len(stack_a);
	//while (calc_chunk_size(stack_a, vars->levers[lev - 1], vars->levers[lev + 1]) > 0)
	while (i > 0)
	{
		if ((*stack_a)->data == vars->max_value)
			rotate_stack(stack_a, vars, "ra\n");
		else
			push_to_b(stack_a, stack_b, vars, lev);
		i--;
	}
}

//push a-values to b according to the chunks
//goal = total number of chunks
//create two chunks for every second lever-value
void	make_chunks(t_list **stack_a, t_list **stack_b, t_index *vars, int goal)
{
	int		lev;
	int		pairs;

	lev = 1;
	pairs = goal;
	if (goal % 2 != 0)
		pairs--;
	while (lev < pairs)
	{
		//printf("Creating chunks between %d and %d, lever is %d\nMax is %d or %d\n", vars->levers[lev - 1], vars->levers[lev + 1], vars->levers[lev], vars->levers[12], vars->levers[13]);
		create_two_chunks(stack_a, stack_b, vars, lev);
		lev += 2;
	}
	//printf("end\n");
	//push the rest to b until only max is left in a
	//printf("Lev after last pair = %d\nCHunk_num = %d\n", lev, vars->chunk_num);
	while ((*stack_a)->next != *stack_a)
	{
		(*stack_a)->chunk = lev;
		if ((*stack_a)->data == vars->max_value)
			rotate_stack(stack_a, vars, "ra\n");
		else
		{
			(*stack_a)->ind = 1;
			push_stack(stack_a, stack_b, vars, "pb\n");
		}
	}
}

int	count_elem(t_list **stack, int n)
{
	int		res;
	t_list	*temp;

	res = 0;
	temp = *stack;
	while (temp)
	{
		if (temp->chunk == n)
			res++;
		temp = temp->next;
		if (temp == *stack)
			break ;
	}
	return (res);
}

void	sort_into_a(t_list **stack_a, t_list **stack_b, t_index *vars, int n)
{
	while ((*stack_b) != NULL)
	{
		add_max_rel(stack_a, stack_b, vars, n);
		n--;
	}
}

void	add_max_rel(t_list **stack_a, t_list **stack_b, t_index *vars, int n)
{
	int	min;
	int	max;

	min = 0;
	max = 0;

	while (count_elem(stack_b, n) > 0)
	{
		calc_borders(stack_b, &min, &max);
		while ((*stack_a)->data != max)
		{
			if ((*stack_b)->ind == 1 && (*stack_b)->chunk == n)
			{
				(*stack_b)->ind = -1;
				rotate_stack(stack_b, vars, "rb\n");
			}
			else if ((*stack_b)->ind == -1 && (*stack_b)->chunk == n)
			{
				(*stack_b)->ind = 1;
				reverse_rotate_stack(stack_b, vars, "rrb\n");
			}
		}
		push_stack(stack_b, stack_a, vars, "pa\n");
	}
	/* while (count_elem(stack_b, n) > 0)
	{
		if ((*stack_b)->chunk == n && (*stack_b)->data < (*stack_a)->data)
			push_stack(stack_b, stack_a, vars, "pa\n");
		else if ((*stack_b)->ind = -1)
		{
			(*stack_b)->ind = -1;
			rotate_stack(stack_a, vars, "rb\n");
		}

	} */
}
void	big_sort(t_list **stack_a, t_list **stack_b, int list_len, t_index *vars)
{
	int		chunk_num;

	chunk_num = ft_sqrt(list_len);
	initialize_array(vars, chunk_num);
	vars->chunk_num = chunk_num;
//	printf("chunk_num = %d\n", vars->chunk_num);
	//(void)stack_b;
	iterate_all_levers(stack_a, vars, vars->chunk_num);
	make_chunks(stack_a, stack_b, vars, vars->chunk_num);
	//sort_into_a(stack_a, stack_b, chunks, chunks->chunk_num);

	free (vars);
}
