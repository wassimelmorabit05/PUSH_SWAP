#include "push_swap.h"

void    rotate(t_ps_list **head)
{
    t_ps_list   *first;
    t_ps_list   *last;

    if (!head || !(*head) || !(*head)->next)
        return ;
    first = *head;
    *head = first->next;

    last = *head;
    while (last->next)
    {
        last = last->next;
    }

    last->next = first;
    first->next = NULL;

}
void ra(t_ps_list **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void rb(t_ps_list **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void rr(t_ps_list **a, t_ps_list **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}