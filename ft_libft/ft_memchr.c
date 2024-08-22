/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:15:24 by jschmitz          #+#    #+#             */
/*   Updated: 2024/05/31 18:41:53 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;

	src = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
/* NOT FINISHED
#include <stdio.h>
#include <string.h>

int main()
{
int	i = 0;
int	c = 0;
const char *s = "Ceci est un test";

while (s[i])
i++;
char c = 'e';
char c1 = 'a';
printf("S: %s\t c: %d\n", s, c);
printf("moi:");
while (c < i)
{
printf("%d", 
c++}
%ld\n ft: %s\n", s, c, ft_memchr(s, c, sizeof(s)), memchr(s, c, sizeof(s))
printf("S: %s\t c1: %d\n moi: %s\n ft: %s\n", s, c1, 
ft_memchr(s, c1, sizeof(s)), memchr(s, c1, sizeof(s)));
return (0);
}*/
