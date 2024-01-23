/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_report.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:31:54 by locharve          #+#    #+#             */
/*   Updated: 2024/01/22 12:38:54 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	smallest_abs(int a, int b)
{
	if (abs_val(a) < abs_val(b))
		return (a);
	else
		return (b);
}

int	simplify_cost(t_node *node, int *cost_from, int *cost_to)
{
	int	result;

	result = smallest_abs(node->cost, node->target->cost);
	if (result == node->cost)
	{
		*cost_from = 0;
		*cost_to = abs_val(node->target->cost) - abs_val(node->cost);
		if (node->cost < 0 && node->target->cost < 0)
			*cost_to *= -1;
	}
	else
	{
		*cost_from = abs_val(node->cost) - abs_val(node->target->cost);
		*cost_to = 0;
		if (node->cost < 0 && node->target->cost < 0)
			*cost_from *= -1;
	}
	return (result);
}

static t_report	*create_report(int cost, char name)
{
	t_report	*result;

	if (cost < 0)
	{
		if (name == 'a')
			result = new_report("ra");
		else if (name == 'b')
			result = new_report("rb");
		else
			result = new_report("rr");
	}
	else
	{
		if (name == 'a')
			result = new_report("rra");
		else if (name == 'b')
			result = new_report("rrb");
		else
			result = new_report("rrr");
	}
	return (result);
}

t_report	*fill_report(int cost, char name)
{
	t_report	*tmp;
	t_report	*result;
	int			i;

	result = NULL;
	i = 0;
	while (i != cost)
	{
		tmp = create_report(cost, name);
		if (!tmp)
		{
			report_clear(result);
			return (NULL);
		}
		report_add_back(&result, tmp);
		if (cost < 0)
			i--;
		else
			i++;
	}
	return (result);
}
