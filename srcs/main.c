/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:00:58 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/16 01:43:33 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(t_index *vars)
{
	write (2, "Error\n", 6);
	free(vars);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_index	*vars;

	stack_a = NULL;
	stack_b = NULL;
	vars = (t_index *)ft_calloc(1, sizeof(t_index));
	if ((!vars))
		return (1);
	if (argc < 2)
		error_message(vars);
	vars->str_arr = argv;
	error_check_num(vars, argc);
	vars->list_len = create_linked_list(vars, &stack_a);
	if (vars->list_len == 0)
		error_message(vars);
	vars->levers = NULL;
	vars->moves[0] = '\0';
	pick_algorithm(&stack_a, &stack_b, vars);
	list_free(&stack_a);
	list_free(&stack_b);
	free(vars->levers);
	free(vars);
	return (0);
}
