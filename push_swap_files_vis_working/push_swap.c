/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:00:58 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/09 18:52:13 by jschmitz         ###   ########.fr       */
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
		return;
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
	int	i;
	int	list_len;
	t_list *stack_a;
	t_list *stack_b;

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
	if (list_len == 0)
		return (printf("Errorstack_a\n"), 0);
/* 	printf("stack a before:\n");
	print_stack(stack_a);
	if (stack_sorted(&stack_a) == 0)
		printf("stack a sorted.\n");
	else
		printf("stack a not sorted.\n"); */
/*  0	printf("stack b before:\n");
	print_stack(stack_b);*/
/* 	if (stack_sorted(&stack_b) == 0)
		printf("stack b sorted.\n");
	else
		printf("stack b not sorted.\n"); */
	//printf("list_len = %d\n", list_len);
	//printf("calculated list_len = %d\n", circ_list_len(&stack_a));
	pick_algorithm(&stack_a, &stack_b, list_len);
	//printf("stack a after algo:\n");
	//print_stack(stack_a);
	//f (stack_sorted(&stack_a) == 0)
	//	printf("stack a sorted.\n");
	//else
	//	printf("stack a not sorted.\n");
	//printf("stack b after algo:\n");
	//print_stack(stack_b);
	list_free(&stack_a);
	list_free(&stack_b);
	return (0);
}
