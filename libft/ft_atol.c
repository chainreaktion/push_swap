/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:19:49 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/02 15:38:33 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	size_t	i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
			i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}
/*
#include <stdlib.h>
#include <stdio.h>

int	main()
{
	char *str1 = "  \t  -1234ab567";
	char *str2 = "---+--+1234ab567";
	char *str3 = "-1234ab567";
	char *str4 = "    +1234ab567";
	char *str5 = "    --+1234ab567";
	char *str6 = "+-1234567";
	char *str7 = "21474836477";
	char *str8 = "-21474836477";
	char *str9 = "21474836488";
	char *str10 = "-21474836488";
	printf("1 -> me: %ld\t atol: %ld\n", ft_atol(str1), atol(str1));
	printf("2 -> me: %ld\t atol: %ld\n", ft_atol(str2), atol(str2));
	printf("3 -> me: %ld\t atol: %ld\n", ft_atol(str3), atol(str3));
	printf("4 -> me: %ld\t atol: %ld\n", ft_atol(str4), atol(str4));
	printf("5 -> me: %ld\t atol: %ld\n", ft_atol(str5), atol(str5));
	printf("6 -> me: %ld\t atol: %ld\n", ft_atol(str6), atol(str6));
	printf("7 -> me: %ld\t atol: %ld\n", ft_atol(str7), atol(str7));
	printf("8 -> me: %ld\t atol: %ld\n", ft_atol(str8), atol(str8));
	printf("9 -> me: %ld\t atol: %ld\n", ft_atol(str9), atol(str9));
	printf("10 -> me: %ld\t atol: %ld\n", ft_atol(str10), atol(str10));
	return (0);
}
 */
