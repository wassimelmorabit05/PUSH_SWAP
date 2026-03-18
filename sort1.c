/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mora <oel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:58:11 by oel-mora          #+#    #+#             */
/*   Updated: 2026/03/18 10:31:54 by oel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ps_list **stack)
{
	t_ps_list	*max;

	max = find_max(*stack);
	if ((*stack)->index == max->index)
		ra(stack);
	else if ((*stack)->next->index == max->index)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	sort_four(t_ps_list **a, t_ps_list **b)
{
	int	pos;

	pos = find_min(*a);
	if (pos == 1)
		ra(a);
	else if (pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (pos == 3)
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_ps_list **a, t_ps_list **b)
{
	int	pos;
	int	size;

	pos = find_min(*a);
	size = ft_list_size(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < size)
			rra(a);
	}
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}
