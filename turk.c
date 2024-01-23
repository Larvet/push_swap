/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:04:00 by locharve          #+#    #+#             */
/*   Updated: 2024/01/22 12:12:32 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_report	*push_first(t_stack *a, t_stack *b)
{
	t_report	*tmp;
	t_report	*result;

	result = NULL;
	while (a->size > 3 && b->size < 2)
	{
		tmp = new_report("pb");
		if (!tmp)
		{
			report_clear(result);
			return (NULL);
		}
		execute_report(a, b, tmp);
		report_add_back(&result, tmp);
	}
	return (result);
}

static t_report	*from_a_to_b(t_stack *a, t_stack *b, t_report *report)
{
	t_report	*tmp;

	while (a->size > 3)
	{
		tmp = cheapest_node(a, b);
		if (!tmp)
		{
			report_clear(report);
			return (NULL);
		}
		execute_report(a, b, tmp);
		report_add_back(&report, tmp);
	}
	return (report);
}

static t_report	*from_b_to_a(t_stack *a, t_stack *b, t_report *report)
{
	t_report	*tmp;

	while (b->size > 0)
	{
		tmp = cheapest_node(b, a);
		if (!tmp)
		{
			report_clear(report);
			return (NULL);
		}
		execute_report(a, b, tmp);
		report_add_back(&report, tmp);
	}
	return (report);
}

t_report	*turk(t_stack *a)
{
	t_stack		b;
	t_report	*tmp;
	t_report	*report;

	ft_bzero(&b, sizeof(b));
	b.name = 'b';
	report = push_first(a, &b);
	if (!report)
		return (NULL);
	if (a->size > 3)
		report = from_a_to_b(a, &b, report);
	if (!check_sort(a->lst, a->size))
	{
		tmp = sort_three(a, &b);
		if (!tmp)
		{
			report_clear(report);
			return (NULL);
		}
		report_add_back(&report, tmp);
	}
	report = from_b_to_a(a, &b, report);
	if (!check_sort(a->lst, a->size))
		report = last_rotation(a, &b, report);
	return (report);
}
