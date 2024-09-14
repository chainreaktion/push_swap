/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:39:06 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/08 21:47:34 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_ptr(char c, int *count);
void	ft_putnbr_hex_ptr(unsigned long nbr, int *count, char casetype);
void	ft_putnbr_ptr(int n, int *count);
void	ft_putstr_ptr(char *s, int *count);
void	ft_unsigned_putnbr_ptr(unsigned int n, int *count);
void	ft_putptr(uintptr_t addr, int *count);
void	ft_args_selector(va_list arguments, char c, int *countaddr);

#endif
