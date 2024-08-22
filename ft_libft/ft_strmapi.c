/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:05:27 by jschmitz          #+#    #+#             */
/*   Updated: 2024/06/08 14:51:47 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//char test_capitalize(unsigned int index, char c);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*res;

	if (!s || !f)
		return (NULL);
	len = (unsigned int)ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>
//char test_capitalize(unsigned int i, char c);

int	main()
{
	const char *str = "dies ist alles klein";
	char *res = ft_strmapi(str, test_capitalize);
//	unsigned int i = 0;
//	char test_capitalize(unsigned int, char);

	printf("Before: %s\n After: %s\n", str, res);
	free(res);
	return (0);
}*/
