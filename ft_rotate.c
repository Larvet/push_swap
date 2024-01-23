/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:47:06 by locharve          #+#    #+#             */
/*   Updated: 2024/01/19 17:47:07 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *stack, int direction)
{
	t_node		*head;
	size_t		i;

	if (!stack || !stack->lst)
		return ;
	head = stack->lst;
	i = 0;
	while (i < stack->size - 1)
	{
		if (direction >= 0)
		{
			ft_swap(&stack->lst->nbr, &stack->lst->prv->nbr);
			stack->lst = stack->lst->prv;
		}
		else if (direction < 0)
		{
			ft_swap(&stack->lst->nbr, &stack->lst->nxt->nbr);
			stack->lst = stack->lst->nxt;
		}
		i++;
	}
	stack->lst = head;
	return ;
}
