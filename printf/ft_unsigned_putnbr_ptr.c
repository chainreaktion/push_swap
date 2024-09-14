/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr_ptr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:01:03 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/08 21:02:19 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_unsigned_putnbr_ptr(unsigned int n, int *count)
{
	if (n > 9)
	{
		ft_unsigned_putnbr_ptr((n / 10), count);
		ft_unsigned_putnbr_ptr((n % 10), count);
	}
	else
	{
		n = (int)(n + '0');
		*count += write (1, &n, 1);
	}
}
