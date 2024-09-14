/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:00:58 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/14 22:39:19 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_index	*vars;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 3)
		error_message();
	error_check_num(argv, argc);
	vars = (t_index *)malloc(sizeof(t_index));
	if (!vars)
		return (1);
	vars->list_len = create_linked_list(argv, &stack_a);
	vars->levers = NULL;
	pick_algorithm(&stack_a, &stack_b, vars);
	list_free(&stack_a);
	list_free(&stack_b);
	free(vars->levers);
	return (0);
}
