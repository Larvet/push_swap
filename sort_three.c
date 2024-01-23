/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:08:53 by locharve          #+#    #+#             */
/*   Updated: 2024/01/18 13:45:12 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_str(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
	return ;
}

static t_report	*two_ops(int prv, int nbr, int nxt)
{
	t_report	*tmp;
	t_report	*result;

	result = NULL;
	tmp = new_report("ra");
	if (!tmp)
		return (NULL);
	report_add_back(&result, tmp);
	tmp = new_report("sa");
	if (!tmp)
	{
		report_clear(result);
		return (NULL);
	}
	report_add_back(&result, tmp);
	if (!(nbr > prv && nbr > nxt))
		swap_str(&result->op, &result->nxt->op);
	return (result);
}

t_report	*sort_three(t_stack *a, t_stack *b)
{
	t_report	*report;
	int			prv;
	int			nbr;
	int			nxt;

	report = NULL;
	prv = a->lst->prv->nbr;
	nbr = a->lst->nbr;
	nxt = a->lst->nxt->nbr;
	if (check_sort(a->lst->prv, a->size))
		report = new_report("rra");
	else if (check_sort(a->lst->nxt, a->size))
		report = new_report("ra");
	else if (prv > nbr && prv > nxt)
		report = new_report("sa");
	else
		report = two_ops(prv, nbr, nxt);
	if (report)
		execute_report(a, b, report);
	return (report);
}
