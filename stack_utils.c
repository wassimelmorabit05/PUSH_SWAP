#include "push_swap.h"

int is_duplicate(t_ps_list *node, int nbr)
{
    if (!node)
        return (0);
    while (node)
    {
        if (node->value == nbr)
            return (1);
        node = node->next;
    }
    return (0);
}
t_ps_list *creat_node(int nbr)
{
    t_ps_list *node;

    node = malloc(sizeof(t_ps_list));
    if (!node)
        return (NULL);
    node->index = 0;
    node->value = nbr;
    node->next= NULL;
    return (node);
}