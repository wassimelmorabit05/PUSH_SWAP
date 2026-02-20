#include "push_swap.h"

t_ps_list	*create_stack(char **args)
{
	t_ps_list	*head;
	t_ps_list	*new_node;
	long nbr;
	int er;
	int i ;

	i = 0;
	while (args[i])
	{
		er = 0;
		nbr = ft_atoi(args[i], &er);
		if (er == 1)
			return (free_list(&head), NULL);
		if (is_duplicate(&head, nbr))
			return (free_list(&head), NULL);
		new_node = create_node(nbr);
		if (!new_node)
			return (free_list(&head), NULL);
		i++;
	}
}
int	main(int ac, char **av)
{
	char		**split_args;
	t_ps_list *a;
	t_ps_list *b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	split_args = check_args(ac, av);
	if (!split_args || !check_is_num(split_args))
		return (write(2, "Error\n", 6), free_split(split_args), 0);
	a = create_stack(split_args);
	if (!a)
		return (write(2, "Error\n", 6), free_split(split_args), 0);
	return (0);
}
