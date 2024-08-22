/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:41:23 by jschmitz          #+#    #+#             */
/*   Updated: 2024/05/31 18:46:01 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int    main()
{
	char *b = "Ceci est un test";
	char *l1 = "est";
	char *l2 = "teste";
	char *l3 = "test";
	char *l4 = "";
	size_t n1 = 10;
	size_t n2 = 20;
	size_t n3 = 0;

	printf("est un test -> %s \n", ft_strnstr(b, l1, n1));
	printf("NULL -> %s\n", ft_strnstr(b, l3, n1));
	printf("NULL -> %s\n", ft_strnstr(b, l2, n3));
	printf("test -> %s\n", ft_strnstr(b, l3, n2));
	printf("Ceci est un test -> %s\n", ft_strnstr(b, l4, n2));
	printf("NULL -> %s\n", ft_strnstr(b, l1, n3));
	return (0);
}*/
