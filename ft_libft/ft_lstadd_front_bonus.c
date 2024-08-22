/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:24:59 by jschmitz          #+#    #+#             */
/*   Updated: 2024/06/07 14:16:19 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//check first that lst and new are no nullpointers
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
	new->next = *lst;
	*lst = new;
	}
}
