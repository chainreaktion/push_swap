/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:19:34 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/05 17:50:35 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//receives stack_a and pointers to the min and max value
void	calc_borders(t_list **stack_a, int *min, int *max)
{
	t_list	*temp;

	*min = 0;
	*max = 0;
	temp = *stack_a;
	while (temp->next != *stack_a)
	{
		if (temp->data > *max)
			*max = temp->data;
		else if (temp->data < *min)
			*min = temp->data;
		temp = temp->next;
	}
	if (temp->data > *max)
		*max = temp->data;
	else if (temp->data < *min)
		*min = temp->data;
}

//calculates the ideal number of elements for each quarter
int	calc_quartersize(int list_len, int min, int max, int)
{
	int	qu_size;

	qu_size = =;
	if (min < 0)
		qu_size = max + (min * -1);
	else
		qu_size = max + min;
	return (qu_size);
}


void	reduce_quarter(t_list **stack_a, t_index in_des, int num)
{
	t_list	*cursor;
	int		cut_off;

	cursor = *stack_a;
	cut_off = in_des->rel_max[num];
	//num = which quarter we are in
	//while : the actual quartersize is bigger than it should be
	while (in_des->(qu_size_ct[num - 1]) > in_des->qu_size && cursor->qu_index == (num - 1))
	{
		while (cursor->next != *stack_a)
		{
			if (cursor->data > in_des->(rel_max[num - 1]))
				cursor->qu_index++;
			cursor = cursor->next;
		}
		if (cursor->data > in_des->(rel_max[num - 1]))
				cursor->qu_index++;
		in_des->(rel_max[num - 1])--;
	}
}


//indexes the real range of each quarter
void	index_quarters(t_list **stack_a, t_index *in_des)
{
	t_list	*cursor;

	ind_des->qu_size_ct[0] = 0;
	ind_des->qu_size_ct[1] = 0;
	ind_des->qu_size_ct[2] = 0;
	ind_des->qu_size_ct[3] = 0;
	cursor = *stack_a;
	while (index_1 != in_des->qu_size || index_2 != in_des->qu_size || index_3 != in_des->qu_size)
	{
		while (cursor->next != *stack_a)
		{
			if (cursor->data >= in_des->min && cursor->data <= in_des->max[0])
			{
				cursor->qu_index = 1;
				ind_des->(qu_size_ct[0])++;
			}
			else if (cursor->data > in_des->max1 && cursor->data <= in_des->max[1])
			{
				cursor->qu_index = 2;
				ind_des->(qu_size_ct[1])++;
			}
			else if (cursor->data > in_des->max2 && cursor->data <= in_des->max[2])
			{
				cursor->qu_index = 3;
				ind_des->(qu_size_ct[2])++;
			}
			else if (cursor->data > in_des->max[2])
			{
				ind_des->(qu_size_ct[3])++;
			}
			cursor = cursor->next;
		}
		printf("Qu_indices: 1=%d, 2=%d, 3=%d, 4=%d\n");
		index_1, index_2, index_3, index_4 = in_des->qu_size;
	}
}
