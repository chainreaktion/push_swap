/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:23:42 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/08 17:00:54 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	big_sort(t_list **stack_a, t_list **stack_b, int list_len)
{
	t_list	*temp;

	list_len +=0;
	temp = *stack_a;
	//while stack a has more than 3 elements
	while (((*stack_a)->next->next->next) != *stack_a)
	{
		//push all to b except the last three
		push_stack(stack_a, stack_b, 'b');
		temp = temp->next;
	}
//	printf("stack a middle:\n");
	//print_stack(*stack_a);
	//printf("stack b middle:\n");
//	print_stack(*stack_b);
	return ;
} */

int	size_pile(t_list **stack_a, int min, int max)
{
	int		res;
	t_list	*temp;

	res = 0;
	temp = *stack_a;
	while (temp->next != *stack_a)
	{
		if (temp->data >= min && temp->data <= max)
			res++;
		temp = temp->next;
	}
	return (res);
}

int	adjust_tercil_max(t_list **stack_a, int min, int max, int goal)
{
	int	tercil_size;

	tercil_size = size_pile(stack_a, min, max);
	if (tercil_size == goal)
		return (max);
	if (tercil_size > goal)
		return(adjust_tercil_max(stack_a, min, max - 1, goal));
	else
		return(adjust_tercil_max(stack_a, min, max + 1, goal));
}

int	adjust_tercil_min(t_list **stack_a, int min, int max, int goal)
{
	int	tercil_size;

	tercil_size = size_pile(stack_a, min, max);
	if (tercil_size == goal)
		return (min);
	if (tercil_size > goal)
		return(adjust_tercil_min(stack_a, min + 1, max, goal));
	else
		return(adjust_tercil_min(stack_a, min - 1, max, goal));
}

void	calculate_piles(t_list **stack_a, int *lever, int list_len)
{
	int tercil_size[3];
	int	goal;
	int	list_len_calc = 0;
	int	end_goal = 0;

	goal = 0;
	calc_borders(stack_a, &lever[0], &lever[3]);
	if (lever[0] < 0)
		lever[1] = (lever[3] + (lever[0] * -1)) / 3;
	else
		lever[1] = (lever[3] - lever[0]) / 3;
	lever[2] = lever[1] * 2;
	goal = list_len / 3;
	end_goal= goal + (list_len % 3);
	tercil_size[0] = size_pile(stack_a, lever[0], lever[1]);
	tercil_size[1] = size_pile(stack_a, lever[1], lever[2]);
	tercil_size[2] = size_pile(stack_a, lever[2], lever[3]);
	list_len_calc = tercil_size[0] + tercil_size[1] + tercil_size[2];
	printf("goal (tercil_size) = %d\nend_goal = %d\n\n", goal, end_goal);
	printf("Before: \nmin = %d\nlever[1] = %d\nlever[2] = %d\nmax = %d\n", lever[0], lever[1], lever[2], lever[3]);
	printf("tercil_size1 = %d\ntercil_size2 = %d\ntercil_size3 = %d\nlist_len calc = %d\n\n", tercil_size[0], tercil_size[1], tercil_size[2], list_len_calc);
	lever[1] = adjust_tercil_max(stack_a, lever[0], lever[1], goal);
	lever[2] = adjust_tercil_min(stack_a, lever[2], lever[3], (goal + (list_len % 3)));

	tercil_size[0] = size_pile(stack_a, lever[0], lever[1]);
	tercil_size[1] = size_pile(stack_a, lever[1], lever[2]);
	tercil_size[2] = size_pile(stack_a, lever[2], lever[3]);
	list_len_calc = tercil_size[0] + tercil_size[1] + tercil_size[2];
	printf("After: \nmin = %d\nlever[1] = %d\nlever[2] = %d\nmax = %d\n", lever[0], lever[1], lever[2], lever[3]);
	printf("After: tercil_size1 = %d\ntercil_size2 = %d\ntercil_size3 = %d\nlist_len calc = %d\n", tercil_size[0], tercil_size[1], tercil_size[2], list_len_calc);
}

/* int	cost_calculation

void	cost_attribution(t_list **stack_a, t_list **stack_b, int *levers)
{
	while (sta)



} */

void	big_sort(t_list **stack_a, t_list **stack_b, int list_len)
{
	t_list	*temp;
	t_list	*next_temp;
	int		count;
	int		levers[4];
	int		len_b;
	int		len_remain;

	if (list_len <= 2)
	 {
        // Handle small case (e.g., manually sort 2 elements)
        if ((*stack_a)->data > (*stack_a)->next->data)
            swap_first_elements(stack_a, 'a');
        return;
    }
	//list_len = circ_list_len(stack_a);
	calculate_piles(stack_a, levers, list_len);
	count = 0;
	temp = *stack_a;

	while (count < list_len)
	//while (count < 10)
	{
		next_temp = temp->next;
		if (temp->data >= levers[1] && temp->data <= levers[2])
		{
			if (*stack_b == NULL || (*stack_b)->next == *stack_b)
				push_stack(stack_a, stack_b, 'b');
			else
			{
				push_stack(stack_a, stack_b, 'b');
				rotate_stack(stack_b, 'b');
			}
		}
		else if (temp->data < levers[1])
			push_stack(stack_a, stack_b, 'b');
		else
			rotate_stack(stack_a, 'a');
		temp = next_temp;
		//next_temp = temp->next;
		count++;
	}
len_remain = circ_list_len(stack_a);
printf("break\n");
big_sort(stack_a, stack_b, len_remain);
if (*stack_a == NULL)
	printf("stack_a = NULL\n");
if (*stack_b == NULL)
	printf("stack_b = NULL\n");
printf("break2\n");
len_b = circ_list_len(stack_b);
big_sort(stack_b, stack_a, len_b);
printf("break3\n");
//while(*stack_b != NULL)
while(circ_list_len(stack_b) > 0)
	push_stack(stack_b, stack_a, 'a');
}
