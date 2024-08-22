/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:05:46 by jschmitz          #+#    #+#             */
/*   Updated: 2024/06/08 14:49:59 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//if (size != 0 && nitems > SIZE_MAX / size)
void	*ft_calloc(size_t nitems, size_t size)
{
	void	*res;

	if (nitems * size > SIZE_MAX)
		return (NULL);
	res = malloc(nitems * size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, nitems * size);
	return (res);
}
