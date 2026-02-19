#include "push_swap.h"

int	main(int ac, char **av)
{
	char		**split_args;

	if (ac < 2)
		return (0);
	split_args = check_args(ac, av);
	if (!split_args || !check_is_num(split_args))
		return (write(2, "Error\n", 6), free_split(split_args), 0);
	return (0);
}
