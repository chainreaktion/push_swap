/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:00:58 by jschmitz          #+#    #+#             */
/*   Updated: 2024/08/25 18:32:46 by jschmitz         ###   ########.fr       */
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

void	create_new_node(t_list *new, )
void	create_list(t_list **stack, char **input)
{
	int	i;
	int	j;
	t_list new;

	i = 1;
	while (input[i] != NULL)
	{
		j = 0;
		while (input[i][j] != '\0')
		{
			if (input[i][j] == ' ')
			{
				j++;
				break;
			}

			ft_lstaddback(t_list **stack, t_list *new)
			j++;
		}
		i++;

	}
}

void	print_stack(t_list stack)
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
	t_list *stack_a;

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
	create_list(t_list **stack_a, char **argv);
	if (stack_a->content == NULL)
		return (write (2, "Errorstack\n", 11), 0);
	print_stack(stack_a);
	return (0);
}
