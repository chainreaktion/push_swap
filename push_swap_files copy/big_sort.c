/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:23:42 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/11 23:37:32 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_tercile_size(t_list **stack, int min, int max)
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

//if tercile is smaller than it should be  > increase lever
//if tercile is bigger than it should be > decrease lever
int	adjust_tercil_max(t_list **stack_a, int *min, int *max_rel, int ter_siz)
{
	int	tercil_size;

	tercil_size = calc_tercile_size(stack_a, *min, *max_rel);
	if (tercil_size == ter_siz)
		return (*max_rel);
	else if (tercil_size > ter_siz)
	{
		(*max_rel)--;
		return (adjust_tercil_max(stack_a, min, max_rel, ter_siz));
	}
	else
	{
		(*max_rel)++;
		return (adjust_tercil_max(stack_a, min, max_rel, ter_siz));
	}
}

int	adjust_tercil_min(t_list **stack_a, int *min_rel, int *max, int ter_siz)
{
	int	tercil_size;

	tercil_size = calc_tercile_size(stack_a, *min_rel, *max);
	if (tercil_size == ter_siz)
		return (*min_rel);
	else if (tercil_size > ter_siz)
	{
		(*min_rel)++;
		return (adjust_tercil_min(stack_a, min_rel, max, ter_siz));
	}
	else
	{
		(*min_rel)--;
		return (adjust_tercil_min(stack_a, min_rel, max, ter_siz));
	}
}

//lever = int array with min (lever[0]), lever1 (lever[1]),
//lever2 (lever[2]) and max (lever[3])
//goal is the size half the pile should have when the lever is correct
void	iterate_levers(t_list **stack_a, t_index *vars)
{
	int		ter_siz;
	//int		list_len;

	//calculate and add min and max to the array
	calc_borders(stack_a, &(vars->levers[0]), &(vars->levers[3]));
	vars->max_value = vars->levers[3];
	//calculate the optimal tercile size
	vars->list_len = circ_list_len(stack_a);
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

void	push_terciles(t_list **stack_a, t_list **stack_b, t_index *vars, int n)
{
	//return ;
	if ((*stack_a)->data == vars->max_value)
		rotate_stack(stack_a, vars, "ra\n");
//case if value is in the first tercile
	if ((*stack_a)->data >= vars->levers[0] && (*stack_a)->data <= vars->levers[1])
	{
//case if this is the first push to b, no rotation needed
		(*stack_a)->ter = n;
		push_stack(stack_a, stack_b, vars, "pb\n");
		if ((*stack_b)->next != *stack_b)
		{
			rotate_stack(stack_b, vars, "rb\n");
		}
	}
//case if value is in the second tercile
	else if ((*stack_a)->data > vars->levers[1] && (*stack_a)->data < vars->levers[2])
	{
		(*stack_a)->ter = n + 1;
		push_stack(stack_a, stack_b, vars, "pb\n");
	}
//case if value is in the third tercile
	else
	{
		(*stack_a)->ter = n + 2;
		rotate_stack(stack_a, vars, "ra\n");
	}
}


void	create_terciles(t_list **stack_a, t_list **stack_b, t_index *vars, int ter_in)
{
	t_list	*temp;
	t_list	*last_node;

	temp = *stack_a;
	last_node = temp->prev;
	while (temp != last_node)
	{
		push_terciles(stack_a, stack_b, vars, ter_in);
		temp = *stack_a;
	}
	push_terciles(stack_a, stack_b, vars, ter_in);
}

/* void	push_terciles_back(t_list **stack_b, t_list **stack_a, t_index *vars, int n)
{
//case if value is in the first tercile
	if ((*stack_b)->ter == n)
	{
		push_stack(stack_b, stack_a, vars, "pa\n");
		rotate_stack(stack_a, vars, "ra\n");
	}
//case if value is in the second tercile
	else if ((*stack_b)->ter == n + 1)
	{
		push_stack(stack_b, stack_a, vars, "pa\n");
	}
//case if value is in the third tercile

	else
	{
		rotate_stack(stack_b, vars, "rb\n");
	}
} */

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

void	mini_sort(t_list **stack_a, int list_len, t_index *vars)
{
	if (stack_sorted(stack_a) == 0)
		return ;
	if (list_len == 2)
		rotate_stack(stack_a, vars, "ra\n");
	else if (list_len == 3)
		sort_stack_three(stack_a, vars);
}

/* void	push_back(t_list **stack_old, t_list **stack_new, t_index *vars, int n)
{
 	mini_sort(stack_new, circ_list_len(stack_new), vars);
	if (count_elem(stack_old, n + 1))

	push_terciles_back(stack_old, stack_new, vars, n);
//exit criteria
	if (n == 1)
		return ;
	if (count_elem(stack_old, n) > 0)
	{
		return (recursive_push_back(stack_old, stack_new, vars, n - 3));
	}
	while (count_elem(stack_old, n > 0))
	{
		push_terciles_back(stack_old, stack_new, vars, n);
		n -= 3;
	}

} */

int	recursive_separation(t_list **stack_a, t_list **stack_b, t_index *vars, int n)
{
	while (circ_list_len(stack_a) >= 5)
	{
		iterate_levers(stack_a, vars);
		create_terciles(stack_a, stack_b, vars, n);
	}
	mini_sort(stack_a, circ_list_len(stack_a), vars);
	//exit condition
	/* if ((stack_a) <= 3)
	{
		//mini_sort(stack_a, circ_list_len(stack_new), vars)
		rotate_stack(stack_a, vars, "ra\n");
		return (n);
	}
//recursion
	else
	{
		return (recursive_separation(stack_a, stack_b, vars, n + 3));
	} */
/* 	while (circ_list_len(stack_a) >= 3)
	{
		iterate_levers(stack_a, vars);
		create_terciles(stack_a, stack_b, vars, n);
		n += 3;
	}
	//rotate_stack(stack_a, vars, "ra\n");*/
	return (n);
}

void	big_sort(t_list **stack_a, t_list **stack_b, t_index *vars)
{
	int	n;

	n = 1;
	iterate_levers(stack_a, vars);
	n = recursive_separation(stack_a, stack_b, vars, n);
	//push_back(stack_b, stack_a, vars, n);
//	sort_into_a
//free the index structure PUT AT THE END
	free (vars);
}
