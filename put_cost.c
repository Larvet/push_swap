/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:53:11 by locharve          #+#    #+#             */
/*   Updated: 2024/01/18 14:06:47 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	evaluate_all_nodes(t_stack *stack)
{
	t_node	*head;
	size_t	i;

	head = stack->lst;
	i = 0;
	while (i < stack->size)
	{
		if (stack->lst->index < stack->size / 2)
			stack->lst->cost = -(stack->lst->index);
		else
			stack->lst->cost = stack->size - stack->lst->index;
		stack->lst = stack->lst->nxt;
		i++;
	}
	stack->lst = head;
	return ;
}

void	put_cost(t_stack *from, t_stack *to)
{
	evaluate_all_nodes(from);
	evaluate_all_nodes(to);
	return ;
}
