/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:49:15 by locharve          #+#    #+#             */
/*   Updated: 2024/01/18 15:30:34 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_cheapest(t_stack *stack)
{
	t_node	*head;
	t_node	*result;
	size_t	i;

	head = stack->lst;
	result = head;
	i = 0;
	while (i < stack->size)
	{
		if (result->abs_cost > stack->lst->abs_cost)
			result = stack->lst;
		stack->lst = stack->lst->nxt;
		i++;
	}
	stack->lst = head;
	return (result);
}

t_report	*cheapest_node(t_stack *from, t_stack *to)
{
	t_node		*cheapest;
	t_report	*report;

	cheapest = NULL;
	report = NULL;
	put_cost(from, to);
	put_target(from, to);
	put_abs_cost(from);
	cheapest = get_cheapest(from);
	report = write_report(from, to, cheapest);
	return (report);
}
