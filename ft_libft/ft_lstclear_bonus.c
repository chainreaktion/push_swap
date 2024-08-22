/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:34:15 by jschmitz          #+#    #+#             */
/*   Updated: 2024/06/08 14:53:05 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	current = *lst;
	while (current)
	{
		temp = current;
		current = current->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}
/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Example del function
void del(void *content)
{
free(content);
}

// Main function to test ft_lstclear
int main()
{
t_list *list = NULL;
t_list *elem1;
t_list *elem2;
t_list *elem3;

// Create list elements
elem1 = ft_lstnew(strdup("Element 1"));
elem2 = ft_lstnew(strdup("Element 2"));
elem3 = ft_lstnew(strdup("Element 3"));

// Add elements to the list
ft_lstadd_back(&list, elem1);
ft_lstadd_back(&list, elem2);
ft_lstadd_back(&list, elem3);

// Clear the list
ft_lstclear(&list, del);

// Verify the list is cleared
if (list == NULL)
{
printf("List successfully cleared.\n");
}
else
{
printf("List clearing failed.\n");
}

return 0;
} */
