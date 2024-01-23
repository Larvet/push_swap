/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_circular.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:06:02 by locharve          #+#    #+#             */
/*   Updated: 2024/01/14 15:56:31 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	list_size(t_node *node, size_t index)
{
	if (node)
	{
		node->index = index;
		return (1 + list_size(node->nxt, index + 1));
	}
	else
		return (0);
}

t_node	*last_node(t_node *node)
{
	if (node)
	{
		if (!node->nxt)
			return (node);
		else
			return (last_node(node->nxt));
	}
	else
		return (NULL);
}

void	be_circular(t_stack *stack)
{
	t_node	*last;

	stack->size = list_size(stack->lst, 0);
	last = last_node(stack->lst);
	last->nxt = stack->lst;
	stack->lst->prv = last;
	return ;
}
