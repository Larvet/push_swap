/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:31:24 by locharve          #+#    #+#             */
/*   Updated: 2024/01/22 12:21:53 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_stack *stack)
{
	t_node	*head;
	t_node	*result;
	size_t	i;
	int		tmp;

	head = stack->lst;
	result = stack->lst;
	tmp = result->nbr;
	i = 0;
	while (i < stack->size)
	{
		if (tmp > stack->lst->nbr)
		{
			result = stack->lst;
			tmp = stack->lst->nbr;
		}
		stack->lst = stack->lst->nxt;
		i++;
	}
	stack->lst = head;
	return (result);
}

t_node	*find_max(t_stack *stack)
{
	t_node	*head;
	t_node	*result;
	size_t	i;
	int		tmp;

	head = stack->lst;
	result = stack->lst;
	tmp = result->nbr;
	i = 0;
	while (i < stack->size)
	{
		if (tmp < stack->lst->nbr)
		{
			result = stack->lst;
			tmp = stack->lst->nbr;
		}
		stack->lst = stack->lst->nxt;
		i++;
	}
	stack->lst = head;
	return (result);
}

static t_node	*get_target(t_stack *to, int nbr, int limit)
{
	t_node	*head;
	t_node	*result;
	size_t	i;

	head = to->lst;
	result = NULL;
	i = 0;
	while (i < to->size)
	{
		if (to->name == 'b' && to->lst->nbr > limit && to->lst->nbr < nbr)
		{
			result = to->lst;
			limit = result->nbr;
		}
		else if (to->name == 'a' && to->lst->nbr < limit && to->lst->nbr > nbr)
		{
			result = to->lst;
			limit = result->nbr;
		}
		to->lst = to->lst->nxt;
		i++;
	}
	to->lst = head;
	return (result);
}

static void	name_target(t_stack *f, t_stack *t, t_node *min, t_node *max)
{
	if (f->name == 'a')
	{
		f->lst->target = get_target(t, f->lst->nbr, min->nbr);
		if (!f->lst->target)
		{
			if (min->nbr < f->lst->nbr)
				f->lst->target = min;
			else
				f->lst->target = max;
		}
	}
	else
	{
		f->lst->target = get_target(t, f->lst->nbr, max->nbr);
		if (!f->lst->target)
		{
			if (max->nbr > f->lst->nbr)
				f->lst->target = max;
			else
				f->lst->target = min;
		}
	}
	return ;
}

void	put_target(t_stack *from, t_stack *to)
{
	t_node	*head;
	t_node	*min;
	t_node	*max;
	size_t	i;

	min = find_min(to);
	max = find_max(to);
	head = from->lst;
	i = 0;
	while (i < from->size)
	{
		name_target(from, to, min, max);
		from->lst = from->lst->nxt;
		i++;
	}
	from->lst = head;
	return ;
}
