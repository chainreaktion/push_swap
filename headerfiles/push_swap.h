/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:40:00 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/16 13:05:11 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "printf.h"
# include "libftprintf.h"
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_list
{
	int				data;
	int				ind;
	int				chunk;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_index
{
	char		**str_arr;
	int			list_len;
	int			*levers;
	int			chunk_num;
	int			max_value;
	int			cost_r_max;
	int			cost_rr_max;
	int			cost_r_min;
	int			cost_rr_min;
	char		moves[5];
}				t_index;

//parsing and creating linked list
t_list	*create_new_node(char *input, int start, t_index *vars);
int		add_new_node(t_list **stack, char *input, t_index *vars, int start);
void	error_check_list(t_index *vars, t_list **stack);
int		create_linked_list(t_index *vars, t_list **stack);
int		running_strings(t_index *vars, t_list **stack, int i, int *list_len);
long	ft_atol(const char *nptr);
int		ft_sqrt(int nb);
int		ft_isalnumextended(int arg);
void	error_check_num(t_index *vars, int argc);
void	list_free(t_list **stack);
void	initialize_array(t_index *vars, int chunk_num);
//operations
void	swap_first_elements(t_list **stack, t_index *chunks, char *move);
void	push_stack(t_list **a, t_list **b, t_index *vars, char *move);
void	remove_from_a(t_list **stack_a);
void	add_to_b(t_list **stack_b, t_list *first_a);
void	rotate_stack(t_list **stack, t_index *chunks, char *move);
void	reverse_rotate_stack(t_list **stack, t_index *chunks, char *move);
//sorting - helper functions
int		stack_sorted(t_list **stack);
void	calc_borders(t_list **stack_a, int *min, int *max);
int		circ_list_len(t_list **stack);
int		calc_chunk_size(t_list **stack, int min, int max);
int		count_elem(t_list **stack, int n);
//printing instructions
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dst, const char *src);
int		pair_check(t_index *vars, char *move2);
void	move_combo(t_index *vars, char *move);
//sorting
void	pick_algorithm(t_list **stack_a, t_list **stack_b, t_index *vars);
void	sort_stack_three(t_list **stack_a, t_index *vars);
void	sort_stack_four(t_list **stack_a, t_list **stack_b, t_index *vars);
void	sort_stack_five(t_list **stack_a, t_list **stack_b, t_index *vars);
void	big_sort(t_list **a, t_list **b, int list_len, t_index *vars);
//big_sort functions
void	make_chunks(t_list **a, t_list **b, t_index *vars, int goal);
void	create_two_chunks(t_list **a, t_list **b, t_index *vars, int lev);
void	push_to_b(t_list **a, t_list **b, t_index *v, int lev);
void	iterate_all_levers(t_list **stack_a, t_index *vars, int max);
int		adjust_lever(t_list **stack_a, t_index *vars, int min, int max_rel);
//sorting back
void	push_all_back(t_list **stack_a, t_list **stack_b, t_index *vars);
void	push_max_or_min(t_list **a, t_list **b, t_index *vars, int max);
void	empty_chunk(t_list **a, t_list **b, t_index *vars, int n);
int		calc_cost_rr_max(t_list **stack_b, int max);
int		calc_cost_r_max(t_list **stack_b, int max);
//test code
void	print_stack(t_list *stack);
void	error_message(t_index *vars);
int		ft_isalnum(int arg);

#endif
