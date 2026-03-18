/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mora <oel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:37:56 by oel-mora          #+#    #+#             */
/*   Updated: 2026/03/17 14:26:52 by oel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	getindex(t_ps_list **stack)
{
	t_ps_list	*i;
	t_ps_list	*j;

	if (!stack || !*stack)
		return ;
	i = *stack;
	while (i)
	{
		i->index = 0;
		j = *stack;
		while (j)
		{
			if (i != j && i->value > j->value)
				i->index++;
			j = j->next;
		}
		i = i->next;
	}
}

t_ps_list	*find_max(t_ps_list *stack)
{
	t_ps_list	*max;

	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (stack->index > max->index)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

int	find_min(t_ps_list *stack)
{
	int	min;
	int	pos;
	int	i;

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
	return (pos);
}
