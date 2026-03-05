/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mora <oel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:57:35 by oel-mora          #+#    #+#             */
/*   Updated: 2026/03/05 14:14:29 by oel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_ps_list **head)
{
	t_ps_list	*first;
	t_ps_list	*second;

	if (!head || !(*head) || !(*head)->next)
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	sa(t_ps_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_ps_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_ps_list **a, t_ps_list **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
