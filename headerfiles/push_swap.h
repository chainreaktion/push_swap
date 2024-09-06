/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:40:00 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/06 22:24:07 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				data;
	int				push_cost;
	//struct s_list 	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

/* typedef struct s_index
{
	//the overall minimum value
	int	min;
	//the overall maximum value
	int	max;
}		t_index; */

# include "libft.h"
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
//remove this later
# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>

//make stack_a
int		error_check(const char *str);
int		ft_isalnumextended(int arg);
long	ft_atol(const char *nptr);
t_list	*create_new_node(char *input, int start);
int		add_new_node(t_list **stack, char *input, int start);
int		error_check_list(t_list **stack);
size_t	create_linked_list(char **input, t_list **stack);
t_list	initialize_structure(t_list index);
void	list_free(t_list **stack);
//operations
void	swap_first_elements(t_list **stack, char stack_name);
void	swap_a_and_b(t_list **stack_a, t_list **stack_b);
void	push_stack(t_list **stack_a, t_list **stack_b, char stack_name);
void	rotate_stack(t_list **stack, char stack_name);
void	rotate_both_stacks(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_stack(t_list **stack, char stack_name);
void	reverse_rotate_both_stacks(t_list **stack_a, t_list **stack_b);
//sorting - helper functions
int		stack_sorted(t_list **stack);
void	calc_borders(t_list **stack_a, int *min, int *max);
//sorting
void	pick_algorithm(t_list **stack_a, t_list **stack_b, int list_len);
void	sort_stack_three(t_list **stack_a);
void	sort_stack_five(t_list **stack_a, t_list **stack_b);
void	big_sort(t_list **stack_a, t_list **stack_b, int list_len);
int		size_pile(t_list **stack_a, int min, int max);
void	calculate_piles(t_list **stack_a, int list_len);
int	adjust_tercil_max(t_list **stack_a, int min, int max, int goal);
int	adjust_tercil_min(t_list **stack_a, int min, int max, int goal);

//test code
void	print_stack(t_list *stack);

#endif



/* typedef struct s_stack
{
	int				stack_size_total;
	int				max_value;
	int				min_value;
	struct s_list 	list_element;
	struct s_stack	*next;
}					t_stack; */
