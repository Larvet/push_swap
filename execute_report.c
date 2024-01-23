/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_report.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:45:39 by locharve          #+#    #+#             */
/*   Updated: 2024/01/23 11:38:41 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_swap(t_stack *a, t_stack *b, char op)
{
	if (a && a->lst && (op == 'a' || op == 's'))
		ft_swap(&a->lst->nbr, &a->lst->nxt->nbr);
	if (b && b->lst && (op == 'b' || op == 's'))
		ft_swap(&b->lst->nbr, &b->lst->nxt->nbr);
	return ;
}

void	do_push(t_stack *a, t_stack *b, char op)
{
	if (op == 'a')
		ft_push(b, a);
	else if (op == 'b')
		ft_push(a, b);
	return ;
}

void	do_rotate(t_stack *a, t_stack *b, char *op)
{
	if (op[0] == 'a')
		ft_rotate(a, -1);
	else if (op[0] == 'b')
		ft_rotate(b, -1);
	else if (op[0] == 'r')
	{
		if (!op[1] || op[1] == '\n')
		{
			ft_rotate(a, -1);
			ft_rotate(b, -1);
		}
		else if (op[1] == 'a')
			ft_rotate(a, 1);
		else if (op[1] == 'b')
			ft_rotate(b, 1);
		else if (op[1] == 'r')
		{
			ft_rotate(a, 1);
			ft_rotate(b, 1);
		}
	}
	return ;
}

void	do_move(t_stack *a, t_stack *b, char *op)
{
	if (op[0] == 's')
		do_swap(a, b, op[1]);
	else if (op[0] == 'p')
	{
		do_push(a, b, op[1]);
		put_index(a);
		put_index(b);
	}
	else if (op[0] == 'r')
		do_rotate(a, b, &op[1]);
	return ;
}

void	execute_report(t_stack *a, t_stack *b, t_report *report)
{
	if (report)
	{
		do_move(a, b, report->op);
		execute_report(a, b, report->nxt);
	}
	return ;
}
