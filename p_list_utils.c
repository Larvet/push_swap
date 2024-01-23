/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:53:23 by locharve          #+#    #+#             */
/*   Updated: 2024/01/12 19:40:53 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int val)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->index = 0;
	new->nbr = val;
	new->prv = NULL;
	new->nxt = NULL;
	return (new);
}

void	list_clear(t_node *lst, size_t size)
{
	if (lst && size > 0)
	{
		if (lst->nxt)
			list_clear(lst->nxt, size - 1);
		free(lst);
	}
	return ;
}

void	list_add_back(t_node **prv, t_node **node, t_node *new)
{
	t_node	*head;

	if (node)
	{
		if (!(*node))
		{
			*node = new;
			(*node)->prv = *prv;
			head = *node;
			while ((*node)->nxt)
				*node = (*node)->nxt;
			(*node)->nxt = NULL;
			*node = head;
		}
		else
			list_add_back(node, &(*node)->nxt, new);
	}
	return ;
}
