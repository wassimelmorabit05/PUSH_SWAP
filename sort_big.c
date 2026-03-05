/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mora <oel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:58:04 by oel-mora          #+#    #+#             */
/*   Updated: 2026/03/05 14:15:17 by oel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(t_ps_list *a)
{
	int	size;

	size = ft_list_size(a);
	if (size <= 100)
		return (18);
	else if (size <= 500)
		return (35);
	else
		return (size / 12);
}

static void	push_to_stack_b(t_ps_list **a, t_ps_list **b, int size, int *i)
{
	if (!a || !*a || !b || !i)
		return ;
	if ((*a)->index <= *i)
	{
		pb(a, b);
		rb(b);
		(*i)++;
	}
	else if ((*a)->index <= *i + size)
	{
		pb(a, b);
		(*i)++;
	}
	else
		ra(a);
}

static int	get_pos(t_ps_list *stack, t_ps_list *max)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == max)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

static void	rotate_to_top(t_ps_list **b, int pos, int size)
{
	if (!b || !*b || pos < 0 || size <= 0)
		return ;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b);
	}
}

void	sort_big(t_ps_list **a, t_ps_list **b)
{
	int			chunk_size;
	int			i;
	int			size;
	int			pos;
	t_ps_list	*max;

	chunk_size = get_chunk_size(*a);
	i = 0;
	while (*a)
		push_to_stack_b(a, b, chunk_size, &i);
	while (*b)
	{
		max = find_max(*b);
		pos = get_pos(*b, max);
		size = ft_list_size(*b);
		rotate_to_top(b, pos, size);
		pa(a, b);
	}
}
