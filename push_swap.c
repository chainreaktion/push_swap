/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:00:58 by jschmitz          #+#    #+#             */
/*   Updated: 2024/08/26 21:21:16 by jschmitz         ###   ########.fr       */
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

int	error_check_doubles(t_list **)
{


}

int	create_new_node(t_list **new_node, char *str, int start)
{
	size_t len;
	char *next_number;

	*new_node = malloc(sizeof(t_list));
	if (*new_node == NULL)
		return (1);
	while (str[start + len] != '\0' && str[start + len] != ' ')
		len++;
	next_number = ft_substr(str, start, len)
	(*new_node)->content = ft_atoi(next_number);
	return (0);
}

int	create_list(t_list **stack, char **input)
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
}
//not sure if it should be *stack ou stack
void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf(%d\n, stack->content);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	output;
	t_list *stack_test;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		if (error_check(argv[i]) == 1)
		{
			write (2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	output = create_list(t_list **stack_test, char **argv);
	if (stack_test->content == NULL)
		return (write (2, "Errorstack\n", 11), 0);
	print_stack(stack_test);
	return (0);
}
