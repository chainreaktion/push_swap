/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:51:52 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/04 17:56:57 by jschmitz         ###   ########.fr       */
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
