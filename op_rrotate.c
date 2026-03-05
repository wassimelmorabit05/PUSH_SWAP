/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mora <oel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:57:30 by oel-mora          #+#    #+#             */
/*   Updated: 2026/03/05 14:13:10 by oel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_ps_list **head)
{
	t_ps_list	*s_last;
	t_ps_list	*last;

	if (!head || !(*head) || !(*head)->next)
		return ;
	s_last = NULL;
	last = *head;
	while (last->next)
	{
		s_last = last;
		last = last->next;
	}
	s_last->next = NULL;
	last->next = *head;
	*head = last;
}

void	rra(t_ps_list **a)
{
	rrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_ps_list **b)
{
	rrotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_ps_list **a, t_ps_list **b)
{
	rrotate(a);
	rrotate(b);
	write(1, "rrr\n", 4);
}
