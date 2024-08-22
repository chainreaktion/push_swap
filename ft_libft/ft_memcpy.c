/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:49:28 by jschmitz          #+#    #+#             */
/*   Updated: 2024/05/31 22:13:18 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char    s[5] = "BBBBB";
	char    dst1[10] = "AAAAAAAAAA";
	char    dst2[10] = "AAAAAAAAAA";
	printf("Before : %s\n", dst1);
	memcpy(dst1 + 5, s, 5);
	ft_memcpy(dst2 + 5, s, 5);
	printf("Dst ft: ");
	for (int i = 0; i < 5; ++i)
	{
		printf("%c", dst1[i]);
	}
	printf("\tDst me: ");
	for (int i = 0; i < 5; ++i)
	{
		printf("%c", dst2[i]);
	}
	return (0);
}*/
