/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:51:52 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/12 00:16:12 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_free(t_list **stack)
{
	t_list	*current;
	t_list	*temp;

	if (!stack || !(*stack))
		return ;
	current = *stack;
	while (current->next != *stack)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(current);
	*stack = NULL;
}

void	index_ini(t_index **vars)
{
	int	i;

	i = 0;
	(*vars)->list_len = 0;
	(*vars)->max_value = 0;
	(*vars)->moves[0] = '\0';
	while (i <= 3)
	{
		(*vars)->ter_siz[i] = 0;
		(*vars)->levers[i] = 0;
		i++;
	}
	(*vars)->levers[i] = 0;
}

int	circ_list_len(t_list **stack)
{
	t_list	*temp;
	int		len;

	if (*stack == NULL)
		return (0);
	temp = *stack;
	len = 0;
	while (temp->next != *stack)
	{
		temp = temp->next;
		len++;
	}
	len++;
	return (len);
}
