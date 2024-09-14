/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:33:32 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/14 17:04:40 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p_temp;

	p_temp = (unsigned char *)s;
	while (n > 0)
	{
		*p_temp = '\0';
		p_temp++;
		n--;
	}
}
