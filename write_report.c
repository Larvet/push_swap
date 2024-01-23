/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_report.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:54:36 by locharve          #+#    #+#             */
/*   Updated: 2024/01/22 10:54:43 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_costs(t_node *cheapest, int *c_from, int *c_to, int *c_both)
{
	if (same_sign(cheapest->cost, cheapest->target->cost))
		*c_both = simplify_cost(cheapest, c_from, c_to);
	else
	{
		*c_from = cheapest->cost;
		*c_to = cheapest->target->cost;
		*c_both = 0;
	}
	return ;
}

static t_report	*cost_to_report(t_report **report, int cost, char c)
{
	t_report	*tmp;

	tmp = fill_report(cost, c);
	if (!tmp)
	{
		report_clear(*report);
		return (NULL);
	}
	report_add_back(report, tmp);
	return (*report);
}

t_report	*write_report(t_stack *from, t_stack *to, t_node *cheapest)
{
	t_report	*tmp;
	t_report	*report;
	int			cost_from;
	int			cost_to;
	int			cost_both;

	report = NULL;
	init_costs(cheapest, &cost_from, &cost_to, &cost_both);
	if (cost_from)
		report = cost_to_report(&report, cost_from, from->name);
	if (cost_to)
		report = cost_to_report(&report, cost_to, to->name);
	if (cost_both)
		report = cost_to_report(&report, cost_both, 'r');
	if (from->name == 'a')
		tmp = new_report("pb");
	else
		tmp = new_report("pa");
	if (!tmp)
	{
		report_clear(report);
		return (NULL);
	}
	report_add_back(&report, tmp);
	return (report);
}
