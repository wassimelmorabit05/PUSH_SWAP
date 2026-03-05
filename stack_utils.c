/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mora <oel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:58:16 by oel-mora          #+#    #+#             */
/*   Updated: 2026/03/05 14:48:18 by oel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_ps_list **head)
{
	t_ps_list	*tmp;
	t_ps_list	*node;

	if (!head || !*head)
		return ;
	node = *head;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	*head = NULL;
}

int	is_duplicate(t_ps_list *node, int nbr)
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

t_ps_list	*ft_create_node(int nbr)
{
	t_ps_list	*node;

	node = malloc(sizeof(t_ps_list));
	if (!node)
		return (NULL);
	node->index = 0;
	node->value = nbr;
	node->next = NULL;
	return (node);
}

void	ft_add_back(t_ps_list **head, t_ps_list *new)
{
	t_ps_list	*last;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = new;
}

int	ft_list_size(t_ps_list *list)
{
	t_ps_list	*tmp;
	int			count;

	tmp = list;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
