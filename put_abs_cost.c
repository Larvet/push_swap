/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_abs_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:16:43 by locharve          #+#    #+#             */
/*   Updated: 2024/01/19 15:10:06 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	same_sign(int a, int b)
{
	if ((a < 0 && b < 0) || (a > 0 && b > 0))
		return (1);
	else
		return (0);
}

static int	biggest_abs(int a, int b)
{
	if (abs_val(a) > abs_val(b))
		return (a);
	else
		return (b);
}

static int	calculate_abs_cost(t_node *node)
{
	if (same_sign(node->cost, node->target->cost))
		return (abs_val(biggest_abs(node->cost, node->target->cost)));
	else
		return (abs_val(node->cost) + abs_val(node->target->cost));
}

void	put_abs_cost(t_stack *stack)
{
	t_node	*head;
	size_t	i;

	head = stack->lst;
	i = 0;
	while (i < stack->size)
	{
		stack->lst->abs_cost = calculate_abs_cost(stack->lst);
		stack->lst = stack->lst->nxt;
		i++;
	}
	stack->lst = head;
	return ;
}
