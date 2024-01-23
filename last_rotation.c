/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:59:33 by locharve          #+#    #+#             */
/*   Updated: 2024/01/22 12:09:08 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_report	*last_report(char *op, size_t limit)
{
	t_report	*tmp;
	t_report	*result;
	size_t		i;

	result = NULL;
	i = 0;
	while (i < limit)
	{
		tmp = new_report(op);
		if (!tmp)
		{
			report_clear(result);
			return (NULL);
		}
		report_add_back(&result, tmp);
		i++;
	}
	return (result);
}

t_report	*last_rotation(t_stack *a, t_stack *b, t_report *report)
{
	t_node		*min;
	t_report	*tmp;

	min = find_min(a);
	if (min->index < a->size / 2)
		tmp = last_report("ra", min->index);
	else
		tmp = last_report("rra", a->size - min->index);
	if (tmp)
	{
		execute_report(a, b, report);
		report_add_back(&report, tmp);
	}
	return (report);
}
