/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:40:00 by jschmitz          #+#    #+#             */
/*   Updated: 2024/08/29 00:12:04 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int			data;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

# include "libft.h"
# include <unistd.h>
# include <stddef.h>
//remove this later
# include <stdio.h>
# include <stdlib.h>

int	error_check(char *str);
int	ft_isalnum(int arg);
void	print_stack(t_list *stack);
int	ft_atoi(const char *nptr);
int	create_new_node(t_list **new_node, char *input, int start);
int	add_new_node(t_list **stack, char *input, int start);
int	error_check_list(t_list **stack);
size_t	create_linked_list(char **input, t_list ***stack, int argc);

#endif
