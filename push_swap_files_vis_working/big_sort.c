/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:23:42 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/13 23:36:30 by jschmitz         ###   ########.fr       */
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
	//printf("Chunk size =%d\n", res);
	return (res);
}

//if chunk is smaller than half the pile  > increase lever
//if chunk is bigger than half the pile > decrease lever
int	adjust_lever(t_list **stack_a, int *min, int *max_rel, int *goal)
{
	int	chunk_size;

	//printf("goal =%d\n", *goal);
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
	//printf("Entering lever iteration\n");
	calc_borders(stack_a, &(chunks->levers[0]), &(chunks->levers[goal]));
	//printf("Borders caclculated\n");
	n = 1;
	//define a;; the lever. For x chunks there are x+1 levers
	while (n < goal)
	{
		//avoid going over the maximum value
		/* if ((chunks->levers[n - 1] + goal) >= chunks->levers[goal])
		{
			chunks->levers[n] = chunks->levers[goal - 1] - 1;
		}
		//naively set next lever to former lever + ideal chunk-size
		else */
		chunks->levers[n] = chunks->levers[n - 1] + goal;
		//printf("Naive lever set\n");
		//adjusting lever so that the number of elements contained is correct
		adjust_lever(stack_a, &(chunks->levers[n - 1]), &(chunks->levers[n]), &goal);
		//adjust_lever(stack_a, &(chunks->levers[n - 1]), &(chunks->levers[n]), &(chunks->chunk_num));
		n++;
	}
	//printf("Levers caclculated\n");
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
	//printf("Entering push_b\n");
	//case if value is between min and lever
	if ((*stack_a)->data >= chunks->levers[n - 1] && (*stack_a)->data <= chunks->levers[n])
	{
		//case if this is the first or second push to b
		/* if (*stack_b == NULL || (*stack_b)->next == *stack_b) */
		if (*stack_b == NULL)
		{
			//printf("Entering first if\n");
			push_stack(stack_a, stack_b, 'b');
		}
		else
		{
			//printf("Entering second if\n");
			push_stack(stack_a, stack_b, 'b');
			rotate_stack(stack_b, 'b');
		}

	}
	//case if value is between max and lever
	else if ((*stack_a)->data > chunks->levers[n] && (*stack_a)->data < chunks->levers[n + 1])
	{
		push_stack(stack_a, stack_b, 'b');
	}
	else
		rotate_stack(stack_a, 'a');
}

void	create_two_chunks(t_list **stack_a, t_list **stack_b, t_index *chunks, int n)
{
	t_list	*temp;
	t_list	*last_node;
	//t_list	*temp;

	temp = *stack_a;
	last_node = temp->prev;
	while (temp != last_node)
	{
		push_to_b(stack_a, stack_b, chunks, n);
		temp = *stack_a;
	}
	//if (temp != *stack_a)
		push_to_b(stack_a, stack_b, chunks, n);
}

//push a-values to b according to the chunks
//goal = total number of chunks
void	make_chunks(t_list **stack_a, t_list **stack_b, t_index *vars, int goal)
{
	int		n;

	n = 1;
	while (n < goal)
	{
		create_two_chunks(stack_a, stack_b, vars, n);
		n += 2;
	}
	while ((*stack_a)->next != *stack_a)
	{
		//push_to_b(stack_a, stack_b, chunks, goal);
		push_stack(stack_a, stack_b, 'b');
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b, int list_len)
{
	t_index	*chunks;

	//number of chunks that will be created in b (square root of the total number of ints, or list_len)
	chunks = (t_index *)malloc(sizeof(t_index));
	if (!chunks)
	{
		printf("Memory allocation chunks failed\n");
		return;
	}
	chunks->chunk_num = ft_sqrt(list_len);
	//printf("List len: %d\nChunk num: %d\n", list_len, chunks->chunk_num);
	//chunks->chunk_num = ft_sqrt(list_len);
	/* chunks->levers = (int*)malloc((chunks->chunk_num) * sizeof(int));
	if (chunks == NULL)
	{
		printf("Levers malloc failed\n");
		return ;
	} */
	//calculate all lever values, including min and max
	iterate_all_levers(stack_a, chunks, chunks->chunk_num);
	//printf("Levers calculated\n");
	//REMOVE FOR-LOOP BELOW
/*  	for (int i = 0; i < chunks->chunk_num; ++i) {
        printf("Lever: %d\n", chunks->levers[i]);
    } */
    //printf("\n");
	make_chunks(stack_a, stack_b, chunks, chunks->chunk_num);
	free (chunks);
	//printf("All pushed to b\n");
}
