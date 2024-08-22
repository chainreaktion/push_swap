/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:41:57 by jschmitz          #+#    #+#             */
/*   Updated: 2024/05/31 18:04:48 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s) + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s) + i);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char *s = "Ceci est un test";

    int c = 'e';
    int c1 = 'a';
    printf("S: %s\t c: %d\n moi: %s\n ft: %s\n", 
	s, c, ft_strchr(s, c), strchr(s, c));
    printf("S: %s\t c1: %d\n moi: %s\n ft: %s\n", 
	s, c1, ft_strchr(s, c1), strchr(s, c1));
    return (0);
}*/
