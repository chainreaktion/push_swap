/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:10:51 by jschmitz          #+#    #+#             */
/*   Updated: 2024/05/31 16:51:52 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void test_capitalize(unsigned int i, char *s);

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

int main()
{
    char str[] = "dies ist alles klein";
	printf("Before: %s\n", str);	
	ft_striteri(str, test_capitalize);
    printf("After: %s\n", str);
    return (0);
}*/
