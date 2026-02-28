#include "push_swap.h"

void	getindex(t_ps_list **stack)
{
	t_ps_list *i;
	t_ps_list *j;

	if (!stack || !*stack)
		return ;

	i = *stack;
	while(i)
	{
		i->index = 0;
		j = *stack;
		while (j)
		{
			if (i->value > j->value)
				i->index++;
			j = j->next;
		}
		i = i->next;
	}
}
t_ps_list   *find_max(t_ps_list *stack)
{
    t_ps_list *max;

    max = stack;
    while (stack)
    {
        if (stack->value > max->value)
            max = stack;
        stack = stack->next;
    }
    return (max);
}

int find_min_pos(t_ps_list *stack)
{
    int min;
    int pos;
    int i;

    min = stack->index;
    pos = 0;
    i = 0;
    while (stack)
    {
        if (stack->index < min)
        {
            min = stack->index;
            pos = i;
        }
        stack = stack->next;
        i++;
    }
    return pos;
}

void	sort_three(t_ps_list **stack)
{
	t_ps_list	*max;

	max = find_max(*stack);
	if ((*stack)->value == max->value)
		ra(stack);
	else if ((*stack)->next->value == max->value)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void sort_four(t_ps_list **a, t_ps_list **b)
{
    int pos;
    int size;

    size = ft_list_size(*a);
    pos = find_min_pos(*a);

    if (pos <= size / 2)
    {
        while (pos-- > 0)
            ra(a);
    }
    else
    {
        while (pos++ < size - 1)
            rra(a);
    }
    pb(b, a);
    sort_three(a);
    pa(a, b);
}

void sort_five(t_ps_list **a, t_ps_list **b)
{
    int pos;

    pos = find_min_pos(*a);
    int size = ft_list_size(*a);

    if (pos <= size / 2)
    {
        while (pos-- > 0)
            ra(a);
    }
    else
    {
        while (pos++ < size - 1)
            rra(a);
    }
    pb(b, a);
    
    sort_four(a, b);
    pa(a, b);
}