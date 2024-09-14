/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:22:26 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/05 14:52:27 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr_ptr(char *s, int *count)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			*count += write (1, &s[i], 1);
			i++;
		}
	}
	else
		ft_putstr_ptr("(null)", count);
}
