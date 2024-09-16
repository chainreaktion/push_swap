/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:39:51 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/16 12:56:44 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_new_node(char *input, int start, t_index *vars)
{
	int		len;
	long	num;
	char	*next_num;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	len = 0;
	while (input[start + len] != '\0' && input[start + len] != ' ')
		len++;
	next_num = ft_substr(input, start, len);
	if (next_num == NULL)
		return (free(new_node), NULL);
	num = ft_atol(next_num);
	if (num > INT_MAX || num < INT_MIN)
	{
		free (next_num);
		error_message(vars);
	}
	new_node->data = (int)num;
	free (next_num);
	return (new_node);
}

int	add_new_node(t_list **stack, char *input, t_index *vars, int start)
{
	t_list	*new_node;
	t_list	*last;

	new_node = create_new_node(input, start, vars);
	if (new_node == NULL)
	{
		list_free(stack);
		free (vars);
		exit (1);
	}
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		last = (*stack)->prev;
		new_node->next = *stack;
		(*stack)->prev = new_node;
		new_node->prev = last;
		last->next = new_node;
	}
	return (1);
}

void	error_check_list(t_index *vars, t_list **stack)
{
	t_list	*temp;
	t_list	*next_node;

	temp = *stack;
	while (temp->next != *stack)
	{
		next_node = temp->next;
		while (next_node != *stack)
		{
			if (temp->data == next_node->data)
			{
				list_free(stack);
				error_message(vars);
			}
			next_node = next_node->next;
		}
		temp = temp->next;
	}
}

int	running_strings(t_index *vars, t_list **stack, int i, int *list_len)
{
	int	j;

	j = 0;
	while (vars->str_arr[i][j] != '\0')
	{
		if (vars->str_arr[i][j] == ' ')
		{
			while (vars->str_arr[i][j] == ' ')
				j++;
			if (vars->str_arr[i][j] == '\0')
				return (i + 1);
		}
		*list_len += add_new_node(stack, vars->str_arr[i], vars, j);
		while (vars->str_arr[i][j] != '\0' && vars->str_arr[i][j] != ' ')
			j++;
	}
	return (i + 1);
}

//case if multiple numbers on one string
int	create_linked_list(t_index *vars, t_list **stack)
{
	int	list_len;
	int	i;

	list_len = 0;
	i = 1;
	if (!vars->str_arr[i][0])
		return (0);
	while (vars->str_arr[i] != NULL)
	{
		i = running_strings(vars, stack, i, &list_len);
	}
	error_check_list(vars, stack);
	return (list_len);
}
