/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:38:55 by jschmitz          #+#    #+#             */
/*   Updated: 2024/05/31 18:43:55 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p_temp;

	p_temp = (unsigned char *)s;
	while (n > 0)
	{
		*p_temp = (unsigned char)c;
		p_temp++;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>

int main()
{
    char    s[10] = "AAAAAAAAAA";
    printf("Before: %s\n", s); 
    ft_memset(s, 'B', sizeof(s));
    printf("Buffer contents my ft: ");
    for (int i = 0; i < sizeof(s); ++i)
    {   
        printf("%c", s[i]);
    }   
    return (0);
}*/