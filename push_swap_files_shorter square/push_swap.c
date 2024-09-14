/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:00:58 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/10 18:47:04 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_check(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '-'
			&& (str[i + 1] == ' ' || str[i + 1] == '-' || str[i + 1] == '\0'))
			return (1);
		if (ft_isalnumextended(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	print_stack(t_list *stack)
{
	t_list	*temp;

	if (stack == NULL)
	{
		printf("Stack is empty\n");
		return ;
	}
	temp = stack;
	printf("%d\n", temp->data);
	temp = temp->next;
	while (temp != stack)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}


int	main(int argc, char **argv)
{
	int		i;
	int		list_len;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		if (error_check(argv[i]) == 1)
			return (write (2, "Error\n", 6), 1);
		i++;
	}
	list_len = create_linked_list(argv, &stack_a);
	error_check_list(&stack_a);
/* 	if (list_len == 0)
		return (printf("Errorstack_a\n"), 0); */
	pick_algorithm(&stack_a, &stack_b, list_len);
	list_free(&stack_a);
	list_free(&stack_b);
	return (0);
}
