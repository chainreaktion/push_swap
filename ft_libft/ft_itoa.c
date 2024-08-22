/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:29:42 by jschmitz          #+#    #+#             */
/*   Updated: 2024/05/29 17:47:48 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_string(char *res, unsigned int n, int pos)
{
	if (n > 9)
		fill_string(res, n / 10, pos - 1);
	res[pos] = (n % 10) + '0';
}

static int	pos_calc(unsigned int n, int pos)
{
	if (n == 0)
		pos = 1;
	while (n != 0)
	{
		pos++;
		n /= 10;
	}
	return (pos);
}

char	*ft_itoa(int n)
{
	int				is_minus;
	int				pos;
	char			*res;
	unsigned int	nb;

	pos = 0;
	is_minus = 0;
	if (n < 0)
	{
		is_minus = 1;
		nb = (unsigned int)(-n);
	}
	else
		nb = (unsigned int)(n);
	pos = pos_calc(nb, pos);
	res = (char *)malloc(sizeof(char) * (pos + is_minus + 1));
	if (res == NULL)
		return (NULL);
	if (is_minus)
		res[0] = '-';
	fill_string(res + is_minus, nb, pos - 1);
	res[pos + is_minus] = '\0';
	return (res);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	int i = 1;
	while (i < argc)
	{
		printf("%s\n", ft_itoa(atoi(argv[i])));
		i++;
	}
	return (0);
}*/
