/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:47:26 by jschmitz          #+#    #+#             */
/*   Updated: 2024/05/29 17:43:35 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*get_word(const char *s, char c)
{
	int		len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

static void	free_split(char **s, int i)
{
	int	c;

	c = 0;
	while (c < i)
	{
		free(s[c]);
		c++;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**arr;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!arr)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			arr[i] = get_word(s, c);
			if (!arr[i])
				return (free_split(arr, i), NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (arr);
}
/*
#include <stdio.h>

int main()
{
	char c = 'c';
	int i;
	const char *str = "UncdeuxctroiscquatreUncdeuxctroiscquatre";
	char **split;

	printf("Inputstring: %s\n Delimiter: %c\n", str, c);
	split = ft_split(str, c);
	i = 0;
	while (split[i] != NULL)
	{
		printf("Result: %s\n", split[i]);
		i++;
	}
	free (split);
	return (0);
}*/
