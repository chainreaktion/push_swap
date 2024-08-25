/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:40:00 by jschmitz          #+#    #+#             */
/*   Updated: 2024/08/25 16:50:55 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
//# include "libft.h"
# include <unistd.h>
# include <stddef.h>
//remove this later
# include <stdio.h>

int	error_check(char *str);
int	ft_isalnum(int arg);

#endif
