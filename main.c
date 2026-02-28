#include "push_swap.h"

t_ps_list	*create_stack(char **args)
{
	t_ps_list	*head;
	t_ps_list	*new_node;
	long nbr;
	int er;
	int i ;

	head = NULL;
	i = 0;
	while (args[i])
	{
		er = 0;
		nbr = ft_atoi(args[i], &er);
		if (er == 1)
			return (free_list(&head), NULL);
		if (is_duplicate(head, nbr))
			return (free_list(&head), NULL);
		new_node = ft_create_node(nbr);
		if (!new_node)
			return (free_list(&head), NULL);
		ft_add_back(&head, new_node);
		i++;
	}
	return (head);
}
void	sorting(t_ps_list **a, t_ps_list **b)
{
	if (!a || !*a)
		return ;

	getindex(a);

	if (ft_list_size(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if (ft_list_size(*a) == 3)
        sort_three(a);
	else if (ft_list_size(*a) == 4)
        sort_four(a, b);
    else if (ft_list_size(*a) == 5)
        sort_five(a, b);
    else
        sort_big(a, b);
}
int	main(int ac, char **av)
{
	char		**split_args;
	t_ps_list *a;
	t_ps_list *b;

	a = NULL;
	if (ac < 2)
		return (0);
	split_args = check_args(ac, av);
	if (!split_args || !check_is_num(split_args))
		return (write(2, "Error\n", 6), free_split(split_args), 0);
	a = create_stack(split_args);
	if (!a)
		return (write(2, "Error\n", 6), free_split(split_args), 0);
	b = NULL;
	if (!is_sorted(a))
		sorting(&a, &b);
	free_list(&a);
	free_list(&b);
	free_split(split_args);
	return (0);
}
