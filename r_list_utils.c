/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:24:54 by locharve          #+#    #+#             */
/*   Updated: 2024/01/18 13:33:24 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_report	*new_report(char *str)
{
	t_report	*result;
	char		*s_dup;

	s_dup = ft_strdup(str);
	if (!s_dup)
		return (NULL);
	result = (t_report *)ft_calloc(1, sizeof(t_report));
	if (!result)
	{
		if (s_dup)
			free(s_dup);
		return (NULL);
	}
	result->op = s_dup;
	return (result);
}

void	report_clear(t_report *lst)
{
	if (lst)
	{
		if (lst->nxt)
			report_clear(lst->nxt);
		free(lst->op);
		free(lst);
	}
	return ;
}

void	report_add_back(t_report **lst, t_report *new)
{
	if (lst)
	{
		if (!(*lst))
			*lst = new;
		else
			report_add_back(&(*lst)->nxt, new);
	}
	return ;
}

void	put_index(t_stack *stack)
{
	t_node	*head;
	size_t	i;

	head = stack->lst;
	i = 0;
	while (i < stack->size)
	{
		stack->lst->index = i;
		stack->lst = stack->lst->nxt;
		i++;
	}
	stack->lst = head;
	return ;
}
