/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:19:49 by jschmitz          #+#    #+#             */
/*   Updated: 2024/05/28 19:19:18 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

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
	char *str7 = "2147483647";
	char *str8 = "-2147483647";
	char *str9 = "2147483648";
	char *str10 = "-2147483648";
	printf("1 -> me: %d\t atoi: %d\n", ft_atoi(str1), atoi(str1));
	printf("2 -> me: %d\t atoi: %d\n", ft_atoi(str2), atoi(str2));
	printf("3 -> me: %d\t atoi: %d\n", ft_atoi(str3), atoi(str3));
	printf("4 -> me: %d\t atoi: %d\n", ft_atoi(str4), atoi(str4));
	printf("5 -> me: %d\t atoi: %d\n", ft_atoi(str5), atoi(str5));
	printf("6 -> me: %d\t atoi: %d\n", ft_atoi(str6), atoi(str6));
	printf("7 -> me: %d\t atoi: %d\n", ft_atoi(str7), atoi(str7));
	printf("8 -> me: %d\t atoi: %d\n", ft_atoi(str8), atoi(str8));
	printf("9 -> me: %d\t atoi: %d\n", ft_atoi(str9), atoi(str9));
	printf("10 -> me: %d\t atoi: %d\n", ft_atoi(str10), atoi(str10));
	return (0);
}*/
