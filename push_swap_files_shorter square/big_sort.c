/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:23:42 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/10 17:46:37 by jschmitz         ###   ########.fr       */
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

//if chunk is smaller than half the pile  > increase lever
//if chunk is bigger than half the pile > decrease lever
int	adjust_lever(t_list **stack_a, int *min, int *max_rel, int *goal)
{
	int	chunk_size;

	chunk_size = calc_chunk_size(stack_a, *min, *max_rel);
	if (chunk_size == *goal)
	//if ((abs(chunk_size - *goal) <= 1))
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

//lever = int array with min (lever[0]), lever (lever[1]) and max (lever[2])
//goal is the size half the pile should have when the lever is correct
void	iterate_all_levers(t_list **stack_a, t_index *chunks, int goal)
{
	int	n;

	initialize_array(chunks);
	//calculate and add min and max to the array
	calc_borders(stack_a, &(chunks->levers[0]), &(chunks->levers[goal]));
	chunks->max_value = chunks->levers[goal];
	n = 1;
	while (n < goal)
	{
		//avoid going over the maximum input value
		if ((chunks->levers[n - 1] + goal) >= chunks->levers[goal])
			chunks->levers[n] = chunks->levers[goal] - 1;
		//naively set next lever to former lever + ideal chunk-size
		else
			chunks->levers[n] = chunks->levers[n - 1] + goal;
		//adjusting lever so that the number of elements contained is correct
		adjust_lever(stack_a, &(chunks->levers[n - 1]), &(chunks->levers[n]), &goal);
		n++;
	}
}

void	initialize_array(t_index *chunks)
{
	chunks->levers = malloc(sizeof(int) * (chunks->chunk_num + 1));
	if (!chunks->levers)
	{
		printf("Memory allocation levers failed\n");
		free(chunks);
		return;
	}
}

void	push_to_b(t_list **stack_a, t_list **stack_b, t_index *chunks, int n)
{
	//never push the max value
	//printf("(*stack_a)->data = %d\nchunks->max_value = %d\n", (*stack_a)->data, chunks->max_value);
	//printf("chunks->levers[n - 1] = %d\nchunks->levers[n] = %d\n", chunks->levers[n - 1], chunks->levers[n]);
	if ((*stack_a)->data == chunks->max_value)
		rotate_stack(stack_a, chunks, "ra\n");
	//case if value is between min and lever
	if ((*stack_a)->data >= chunks->levers[n - 1] && (*stack_a)->data <= chunks->levers[n])
	{
		//case if this is the first push to b, no rotation needed
		if (*stack_b == NULL)
			push_stack(stack_a, stack_b, chunks, "pb\n");
		else
		{
			push_stack(stack_a, stack_b, chunks, "pb\n");
			rotate_stack(stack_b, chunks, "rb\n");
		}
	}
	//case if value is between max and lever
	else if ((*stack_a)->data > chunks->levers[n] && (*stack_a)->data < chunks->levers[n + 1])
		push_stack(stack_a, stack_b, chunks, "pb\n");
	//if the node is not in the current chunk, put it to the bottom of stack a for now
	else
		rotate_stack(stack_a, chunks, "ra\n");
}

void	create_two_chunks(t_list **stack_a, t_list **stack_b, t_index *chunks, int n)
{
	t_list	*temp;
	t_list	*last_node;

	temp = *stack_a;
	last_node = temp->prev;
	while (temp != last_node)
	{
		push_to_b(stack_a, stack_b, chunks, n);
		temp = *stack_a;
	}
	push_to_b(stack_a, stack_b, chunks, n);
}

//push a-values to b according to the chunks
void	make_chunks(t_list **stack_a, t_list **stack_b, t_index *chunks, int goal)
{
	int		n;

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
}

void	big_sort(t_list **stack_a, t_list **stack_b, int list_len, t_index *chunks)
{
	chunks->chunk_num = ft_sqrt(list_len);
	iterate_all_levers(stack_a, chunks, chunks->chunk_num);
	make_chunks(stack_a, stack_b, chunks, chunks->chunk_num);
//	sort_into_a
//free the index structure PUT AT THE END
	free (chunks);
}
