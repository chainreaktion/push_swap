/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:19:34 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/13 22:03:23 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_borders(t_list **stack_a, int *min, int *max)
{
	t_list	*temp;

//	printf("Entered calc borders\n");
	temp = *stack_a;
	*min = temp->data;
	*max = temp->data;
	while (1)
	{
		if (temp->data > *max)
		{
			*max = temp->data;
		}
		else if (temp->data < *min)
		{
			*min = temp->data;
		}

		if (temp->next == *stack_a)
			break ;
		temp = temp->next;
	}
}

//array of two strings in the index struct. Each move sends a string to the structurr
//if there already is a move in the first str, see if they can be combined, otherwise
//replace the first move with the incoming
int	pair_check(t_index *chunks,  char *move2)
{
	if (ft_strncmp(chunks->moves, "sa\n", 3) == 0
		&& ft_strncmp(move2, "sb\n", 3) == 0)
	{
		ft_strlcpy(chunks->moves, "ss\n", 4);
		return (1);
	}
	else if (ft_strncmp(chunks->moves, "ra\n", 3) == 0
		&& ft_strncmp(move2, "rb\n", 3) == 0)
	{
		ft_strlcpy(chunks->moves, "rr\n", 4);
		return (1);
	}
	else if (ft_strncmp(chunks->moves, "rra\n", 4) == 0
		&& ft_strncmp(move2, "rrb\n", 4) == 0)
	{
		ft_strlcpy(chunks->moves, "rrr\n", 5);
		return (1);
	}
	else if (ft_strncmp(chunks->moves, "sb\n", 3) == 0
		&& ft_strncmp(move2, "sa\n", 3) == 0)
	{
		ft_strlcpy(chunks->moves, "ss\n", 4);
		return (1);
	}
	else if (ft_strncmp(chunks->moves, "rb\n", 3) == 0
		&& ft_strncmp(move2, "ra\n", 3) == 0)
	{
		ft_strlcpy(chunks->moves, "rr\n", 4);
		return (1);
	}
	else if (ft_strncmp(chunks->moves, "rrb\n", 4) == 0
		&& ft_strncmp(move2, "rra\n", 4) == 0)
	{
		ft_strlcpy(chunks->moves, "rrr\n", 5);
		return (1);
	}
	else if (ft_strncmp(move2, "pa\n", 3) == 0 || ft_strncmp(move2, "pb\n", 3) == 0)
		return (0);
	else
		return (2);
}

void	move_combo(t_index *chunks, char *move)
{
	int	pairs;

	pairs = pair_check(chunks, move);
	//if (chunks->moves == NULL || pairs == 2)
	if (pairs == 0)
	{
		printf("%s", chunks->moves);
		printf("%s", move);
		chunks->moves[0] = '\0';
	}
	else if (pairs == 1)
	{
		printf("%s", chunks->moves);
		chunks->moves[0] = '\0';
	}
	if (pairs == 2)
	{
		if (chunks->moves[0] != '\0')
			printf("%s", chunks->moves);
		ft_strlcpy(chunks->moves, move, ft_strlen(move) + 1);
	}
}
//puts all the output moves into a string in order to combine them
/* void	create_moves(t_index *chunks, char *move)
{
	if (chunks->output_moves == NULL)
	chunks->output_moves = malloc(sizeof(char));
	if (move)
}

void	parse_ouput_moves(t_index *chunks)
{
	while (chunks->output_moves != '\0')
	{



	}
	free()
	free(chunks);
} */
/* int	calc_push_cost(t_list **stack_a, )
{


}  */
