/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:00:58 by jschmitz          #+#    #+#             */
/*   Updated: 2024/09/02 21:46:59 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_check(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (ft_isalnumextended(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	print_stack(t_list *stack)
{
	t_list	*temp;

	if (stack == NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	temp = stack;
	printf("%d\n", temp->data);
    temp = temp->next;
	while (temp != stack)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}



int	main(int argc, char **argv)
{
	int	i;
	int	list_len;
	t_list *stack_a;
	t_list *stack_b;
	char	*str = "11 22 33 44 55";
	char **argb;
//	int	output = 0;

	argb = malloc(2 * sizeof(char *));
    if (argb == NULL)
    {
        perror("Failed to allocate memory argb");
        return 1;
    }
	argb[0] = NULL;
	argb[1] = str;
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		if (error_check(argv[i]) == 1)
			return (write (2, "Error\n", 6), 1);
		i++;
	}
	list_len = create_linked_list(argv, &stack_a);
	if (list_len == 0)
		return (printf("Errorstack_a\n"), 0);
	printf("stack a before:\n");
	print_stack(stack_a);
	if (stack_sorted(&stack_a) == 0)
		printf("stack a sorted.\n");
	else
		printf("stack a not sorted.\n");
	list_len = create_linked_list(argb, &stack_b);
	if (list_len == 0)
		return (printf("Errorstack_b\n"), 0);
	printf("stack b before:\n");
	print_stack(stack_b);
	if (stack_sorted(&stack_b) == 0)
		printf("stack b sorted.\n");
	else
		printf("stack b not sorted.\n");
/* 	output = swap_first_elements(&stack_a);
	if (output == 1)
		return (printf("Errorswapa\n"), 0);
	printf("stack a after swap:\n");
	print_stack(stack_a);
	printf("stack b after swap:\n");
	print_stack(stack_b);  */
/* 	output = swap_a_and_b(&stack_a, &stack_b);
	if (output == 1)
		return (printf("Errorswap\n"), 0); */
/* 	output = push_stack(&stack_a, &stack_b);
	if (output == 1)
		return (printf("Errorpushstack\n"), 0); */
	reverse_rotate_both_stacks(&stack_a, &stack_b);
	printf("stack a after swap:\n");
	print_stack(stack_a);
	if (stack_sorted(&stack_a) == 0)
		printf("stack a sorted.\n");
	else
		printf("stack a not sorted.\n");
	printf("stack b after swap:\n");
	print_stack(stack_b);
	if (stack_sorted(&stack_b) == 0)
		printf("stack b sorted.\n");
	else
		printf("stack b not sorted.\n");
	return (0);
}
