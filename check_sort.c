/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:58:34 by locharve          #+#    #+#             */
/*   Updated: 2024/01/23 13:32:57 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_node *lst, size_t size)
{
	t_node	*head;
	size_t	i;

	head = lst;
	i = 0;
	while (i < size - 1)
	{
		if (lst->nbr >= lst->nxt->nbr)
		{
			lst = head;
			return (0);
		}
		lst = lst->nxt;
		i++;
	}
	lst = head;
	return (1);
}
