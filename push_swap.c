/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:00:58 by jschmitz          #+#    #+#             */
/*   Updated: 2024/08/28 23:45:56 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check if input is string or strings
//check for doubles or invalid char

int	error_check(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
/*
int	error_check_doubles(t_list **)
{


}*/
/* \int	create_list(t_list **stack, char **input)
{
	int	i;
	int	j;
	int	output;
	t_list *new;

	i = 1;
	while (input[i] != NULL)
	{
		j = 0;
		while (input[i][j] != '\0')
		{
			//case if multiple numbers on one string
			if (input[i][j] == ' ')
			{
				i++;
				break;
			}
			output = create_new_node(&new, input[i], j);
			if (output != 0)
				return (1);
			ft_lstaddback(t_list **stack, t_list *new)
			j++;
		}
		i++;
	}
	return (0);
} */
void	print_stack(t_list *stack)
{
	t_list	*temp;

	if (stack == NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	temp = stack;
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
	t_list **stack_test;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		if (error_check(argv[i]) == 1)
			return (write (2, "Error\n", 6), 1);
		i++;
	}
	list_len = create_linked_list(argv, &stack_test, argc);
	if (list_len == 0)
		return (write (2, "Errorstack\n", 11), 0);
	/* if ((*stack_test)->data == NULL)
		return (write (2, "Errorstack\n", 11), 0); */
	print_stack(*stack_test);
	return (0);
}
