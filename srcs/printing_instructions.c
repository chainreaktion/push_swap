/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:23:24 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/16 02:57:22 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strcpy(char *dst, const char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	pair_check(t_index *vars, char *move2)
{
	if (((!ft_strcmp(vars->moves, "sa\n")) && (!ft_strcmp(move2, "sb\n")))
		|| ((!ft_strcmp(vars->moves, "sb\n")) && (!ft_strcmp(move2, "sa\n"))))
	{
		return (ft_strcpy(vars->moves, "ss\n"), 1);
	}
	else if (((!ft_strcmp(vars->moves, "ra\n")) && (!ft_strcmp(move2, "rb\n")))
		|| ((!ft_strcmp(vars->moves, "rb\n")) && (!ft_strcmp(move2, "ra\n"))))
	{
		return (ft_strcpy(vars->moves, "rr\n"), 1);
	}
	else if (((!ft_strcmp(vars->moves, "rra\n")) && (!ft_strcmp(move2, "rrb\n")))
		|| ((!ft_strcmp(vars->moves, "rrb\n")) && (!ft_strcmp(move2, "rra\n"))))
	{
		return (ft_strcpy(vars->moves, "rrr\n"), 1);
	}
	else if (((!ft_strcmp(vars->moves, "sa\n")) && (!ft_strcmp(move2, "sb\n")))
		|| ((!ft_strcmp(vars->moves, "sb\n")) && (!ft_strcmp(move2, "sa\n"))))
	{
		return (ft_strcpy(vars->moves, "ss\n"), 1);
	}
	else if (!(ft_strcmp(move2, "pa\n")) || (!ft_strcmp(move2, "pb\n")))
		return (0);
	else
		return (2);
}

//array of two strings in the index struct. Each move sends a
//string to the structure if there already is a move in the
//first str, see if they can be combined, otherwise
//replace the first move with the incoming
void	move_combo(t_index *vars, char *move)
{
	int	pairs;

	if (move == NULL && vars->moves[0] != '\0')
		ft_printf("%s", vars->moves);
	if (move == NULL)
		return ;
	pairs = pair_check(vars, move);
	if (pairs == 0)
	{
		ft_printf("%s", vars->moves);
		ft_printf("%s", move);
		vars->moves[0] = '\0';
	}
	else if (pairs == 1)
	{
		ft_printf("%s", vars->moves);
		vars->moves[0] = '\0';
	}
	else if (pairs == 2)
	{
		if (vars->moves[0] != '\0')
			ft_printf("%s", vars->moves);
		ft_strcpy(vars->moves, move);
	}
}
