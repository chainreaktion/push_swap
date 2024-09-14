/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:39:51 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/10 18:40:21 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_new_node(char *input, int start)
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
	num = atol(next_num);
	if (num > INT_MAX || num < INT_MIN)
	{
		printf("Error\n");
		return (new_node = NULL);
	}
	new_node->data = (int)num;
	free (next_num);
	return (new_node);
}

int	add_new_node(t_list **stack, char *input, int start)
{
	t_list	*new_node;
	t_list	*last;

	new_node = create_new_node(input, start);
	if (new_node == NULL)
		exit (0);
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

void	error_check_list(t_list **stack)
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
				printf("Error\n");
				exit (0);
			}
			next_node = next_node->next;
		}
		temp = temp->next;
	}
}

size_t	create_linked_list(char **input, t_list **stack)
{
	size_t	list_len;
	int		i;
	int		j;

	list_len = 0;
	i = 1;
	while (input[i] != NULL)
	{
		j = 0;
		while (input[i][j] != '\0')
		{
			if (input[i][j] == ' ')
			{
				while (input[i][j] == ' ')
					j++;
				if (input[i++][j] == '\0')
					break ;
			}
			list_len += add_new_node(stack, input[i], j);
			while (input[i][j] != '\0' && input[i][j] != ' ')
				j++;
		}
		i++;
	}
	return (list_len);
}
