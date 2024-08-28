/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:39:51 by jschmitz          #+#    #+#             */
/*   Updated: 2024/08/29 00:15:52 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_new_node(t_list **new_node, char *input, int start)
{
	int		len;
	char	*next_num;

	*new_node = malloc(sizeof(t_list));
	if (*new_node == NULL)
		return (1);
	len = 0;
	while (input[start + len] != '\0' && input[start + len] != ' ')
		len++;
	next_num = ft_substr(input, start, len);
	if (next_num == NULL)
		return (free(*new_node), 1);
	(*new_node)->data = atoi(next_num);
	free (next_num);
	return (0);
}

int	add_new_node(t_list **stack, char *input, int start)
{
	t_list *new_node;
	t_list *last;
	int		output;

	output = create_new_node(&new_node, input, start);
	if (output == 1)
		return (1);
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		last = (*stack)->prev;
		new_node->next = *stack;
		(*stack)->prev = new_node;
		new_node->prev = last;
		last->next = new_node;
	}
	return (0);
}

int	error_check_list(t_list **stack)
{
	t_list	*temp;
	t_list	*next;

	temp = *stack;
	while (temp != *stack)
	{
		while (next != *stack)
		{
			if (temp->data == next->data)
				return (1);
			next = next->next;
		}
		temp = temp->next;
	}
	return (0);
}

size_t	create_linked_list(char **input, t_list ***stack, int argc)
{
	size_t	list_len;
	int		i;
	int		j;
	int	output;

	list_len = 0;
	/* if (!input)
		return (0); */
	i = 1;
	//alternative: (input[i] != NULL) But not sure if there
	// is a NULL in the argv-array
	while (i < argc)
	{
		j = 0;
		while (input[i][j] != '\0')
		{
			//case if multiple numbers on one string
			if (input[i][j] == ' ')
			{
				while (input[i][j] == ' ')
					j++;
				i++;
				break;
			}
			output = add_new_node(*stack, input[i], j);
			if (output != 0)
				return (0);
			j++;
		}
		i++;
	}
	if (error_check_list(*stack) == 1)
	{
		write (2, "ErrorDoublon\n", 13);
		return (0);
	}
	return (list_len);
}

