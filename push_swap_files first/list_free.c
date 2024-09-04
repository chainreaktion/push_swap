/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:51:52 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/03 17:42:32 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
