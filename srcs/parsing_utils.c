/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:52:46 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/14 22:15:38 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//modified for push_swap to include space
// Returns 1 for valid characters ('0'-'9', space, and '-')
int	ft_isalnumextended(int arg)
{
	return ((arg >= '0' && arg <= '9')
		|| arg == ' ' || arg == '-' || arg == '+');
}

int	ft_isalnum(int arg)
{
	return ((arg >= '0' && arg <= '9'));
}

void	error_check_num(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isalnumextended(argv[i][j]) == 0)
				error_message();
			if ((argv[i][j] == '-' || argv[i][j] == '+')
				&& ft_isalnum(argv[i][j + 1]) == 0)
				error_message();
			j++;
		}
		i++;
	}
}

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

void	struct_free(t_index *vars)
{
	free(vars->levers);
	//free (vars->moves);
	free(vars);
}

void	initialize_array(t_index *vars, int chunk_num)
{
	int	i;

	i = 0;
	vars->levers = malloc(sizeof(int) * (chunk_num + 1));
	if (!vars->levers)
	{
		free(vars);
		exit (0);
	}
	while (i < vars->chunk_num + 1)
	{
		vars->levers[i] = 0;
		i++;
	}
}
