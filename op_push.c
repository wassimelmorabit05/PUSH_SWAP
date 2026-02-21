#include "push_swap.h"

void	push(t_ps_list **src, t_ps_list **dest)
{
	t_ps_list	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}
void pa(t_ps_list **a, t_ps_list **b)
{
    push (b, a);
    write (1, "pa\n", 3);
}
void pb(t_ps_list **a, t_ps_list **b)
{
    push (a, b);
    write (1, "pa\n", 3);
}