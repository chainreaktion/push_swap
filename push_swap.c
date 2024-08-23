#include "push_swap.h"

//check if input is string or strings
//check for doubles or invalid char

int	error_check(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str)
	{
		if (ft_isalnum(str[i]) == 0)
			return (write (2, "Error\n", 6));
		i++;
	}
	if (str = )
}
int	main(int argc, char **argv)
{
	if (error_check(stack_a) == 1)
	{
		write (2, "Error\n", 6);
		return (1);
	}
}
