/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:29:51 by jschmitz          #+#    #+#             */
/*   Updated: 2024/05/31 15:08:28 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		write (fd, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_fd((int)(nb / 10), fd);
		ft_putnbr_fd((int)(nb % 10), fd);
	}
	else
	{
		nb = (int)(nb + '0');
		write (fd, &nb, 1);
	}
}
/*
int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	ft_putnbr_fd(atoi(argv[2]), atoi(argv[1]));
	return (0);
}*/
