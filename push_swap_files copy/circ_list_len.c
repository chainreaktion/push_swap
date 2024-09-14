/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_list_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:01:24 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/11 22:03:29 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
