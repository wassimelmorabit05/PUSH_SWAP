/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mora <oel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:57:20 by oel-mora          #+#    #+#             */
/*   Updated: 2026/03/05 14:23:32 by oel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	pa(t_ps_list **a, t_ps_list **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_ps_list **a, t_ps_list **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
