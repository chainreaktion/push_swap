/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:51:52 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/10 21:56:39 by jschmitz         ###   ########.fr       */
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

/* void	index_free(t_index *chunks)
{
	if (!chunks || !(*stack))
		return ;


} */
