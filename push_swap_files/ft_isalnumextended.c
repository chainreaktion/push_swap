/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnumextended.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:07:16 by jschmitz          #+#    #+#             */
/*   Updated: 2024/08/31 01:07:22 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//modified for push_swap to include space
int	ft_isalnumextended(int arg)
{
	return ((arg >= '0' && arg <= '9') || arg == ' ' || arg == '-');
}
