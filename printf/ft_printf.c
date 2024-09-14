/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:40:33 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/08 22:08:37 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start (arguments, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format [i] != '%')
		{
			ft_putchar_ptr(format[i], &count);
		}
		else
		{
			ft_args_selector(arguments, format[i + 1], &count);
			i++;
		}
		i++;
	}
	return (count);
	va_end (arguments);
	return (count);
}
/* #include <limits.h>
#include <stdio.h>

int main()
{
	char	*str = "Dies ist ein Test-String";
	char 	*empty = "\0";
	char	*nothing = NULL;
	char	c = 'o';
	int		ret;
	int	Zahl = 99;
	int Zahl1 = 45738472;
	unsigned long unsign = ULONG_MAX;

	ret = ft_printf("String (s): %s\t", str);
	printf("%d\n", ret);
	ret = printf("String (s): %s\t", str);
	printf("%d\n", ret);

	ret = ft_printf("Empty string (s): %s\t", empty);
	printf("%d\n", ret);
	ret = printf("Empty string (s): %s\t", empty);
	printf("%d\n", ret);

	ret = ft_printf("Nullstring (s): %s\t", nothing);
	printf("%d\n", ret);
	ret = printf("Nullstring (s): %s\t", nothing);
	printf("%d\n", ret);

	ret = ft_printf("'o' (c): %c\t", c);
	printf("%d\n", ret);
	ret = printf("'o' (c): %c\t", c);
	printf("%d\n", ret);

	ret = ft_printf("Prozent: %%\t");
	printf("%d\n", ret);
	ret = printf("Prozent: %%\t");
	printf("%d\n", ret);

	ret = ft_printf("Int32max (d): %d\t", INT32_MAX);
	printf("%d\n", ret);
	ret = printf("Int32max (d): %d\t", INT32_MAX);
	printf("%d\n", ret);

	ret = ft_printf("Int32min (d): %d\t", INT32_MIN);
	printf("%d\n", ret);
	ret = printf("Int32min (d): %d\t", INT32_MIN);
	printf("%d\n", ret);

	ret = ft_printf("Int64max (d): %d\t", INT64_MAX);
	printf("%d\n", ret);
	ret = printf("Int64max (d): %d\t", INT64_MAX);
	printf("%d\n", ret);

	ret = ft_printf("Int64min (d): %d\t", INT64_MIN);
	printf("%d\n", ret);
	ret = printf("Int64max (d): %d\t", INT64_MIN);
	printf("%d\n", ret);

	ret = ft_printf("Unsigned long max (u): %u\t", (unsigned int)unsign);
	printf("%d\n", ret);
	ret = printf("Unsigned long max (u): %u\t", (unsigned int)unsign);
	printf("%d\n", ret);

	unsign = LONG_MIN;

	ret = ft_printf("Long min (u): %u\t", (unsigned int)unsign);
	printf("%d\n", ret);
	ret = printf("Long min (u): %u\t", (unsigned int)unsign);
	printf("%d\n", ret);

	unsign = -555;

	ret = ft_printf("Unsigned int -555 (u): %u\t", (unsigned int)unsign);
	printf("%d\n", ret);
	ret = printf("Unsigned int -555 (u): %u\t", (unsigned int)unsign);
	printf("%d\n", ret);

	ret = ft_printf("Stringadresse (p): %p\t", str);
	printf("%d\n", ret);
	ret = printf("Stringadresse (p): %p\t", str);
	printf("%d\n", ret);

	ret = ft_printf("Intadresse (p): %p\t", &Zahl);
	printf("%d\n", ret);
	ret = printf("Intadresse (p): %p\t", &Zahl);
	printf("%d\n", ret);

	ret = ft_printf("Integer: %d\t", Zahl);
	printf("%d\n", ret);
	ret = printf("Integer: %d\t", Zahl);
	printf("%d\n", ret);

	ret = ft_printf("Hexamin (x): %x\t", Zahl1);
	printf("%d\n", ret);
	ret = printf("Hexamin (x): %x\t", Zahl1);
	printf("%d\n", ret);

	ret = ft_printf("Hexamaj (X): %X\t", Zahl1);
	printf("%d\n", ret);
	ret = printf("Hexamaj (X): %X\t", Zahl1);
	printf("%d\n", ret);

	return (0);
} */
