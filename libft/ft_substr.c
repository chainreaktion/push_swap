/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:17:44 by jschmitz          #+#    #+#             */
/*   Updated: 2024/08/29 00:16:56 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*res;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	//replace calloc by ft_calloc
	if (start >= s_len)
		return (calloc(1, 1));
	if (start + len > s_len)
		len = s_len - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>

int	main()
{
	char *str = "i just want this part #############";
	size_t size = 10;
	char *ret = ft_substr(str, 5, size);

	printf("Str: %s\nSize: %zu\n Res: %s\n", str, size, ret);
	return (0);
}*/
