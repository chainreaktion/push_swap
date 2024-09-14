/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:11:19 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/08 22:00:51 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_ptr(int n, int *count)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		*count += write (1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_ptr((int)(nb / 10), count);
		ft_putnbr_ptr((int)(nb % 10), count);
	}
	else
	{
		nb = (int)(nb + '0');
		*count += write (1, &nb, 1);
	}
}
