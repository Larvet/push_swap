/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_same_nbrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:23:45 by locharve          #+#    #+#             */
/*   Updated: 2024/01/14 16:08:04 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	no_same_nbrs(t_stack *stack)
{
	t_node	*head;
	t_node	*tmp;
	size_t	i[2];

	head = stack->lst;
	i[0] = 0;
	while (i[0] < stack->size)
	{
		tmp = stack->lst->nxt;
		i[1] = i[0] + 1;
		while (i[1] < stack->size && tmp->nbr != stack->lst->nbr)
		{
			tmp = tmp->nxt;
			i[1] += 1;
		}
		if (i[1] < stack->size)
			break ;
		stack->lst = stack->lst->nxt;
		i[0] += 1;
	}
	stack->lst = head;
	if (i[0] < stack->size)
		return (0);
	else
		return (1);
}
