void	mini_sort(t_list **stack_a, int list_len, t_index *vars)
{
	if (stack_sorted(stack_a) == 0)
		return ;
	if (list_len == 2)
		rotate_stack(stack_a, vars, "ra\n");
	else if (list_len == 3)
		sort_stack_three(stack_a, vars);
}
