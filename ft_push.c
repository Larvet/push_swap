/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:34:46 by locharve          #+#    #+#             */
/*   Updated: 2024/01/19 17:46:52 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_dst_0(t_node **src, t_node **dst)
{
	t_node	*tmp_prv;

	tmp_prv = (*src)->prv;
	*dst = *src;
	*src = (*src)->nxt;
	(*src)->prv = tmp_prv;
	(*src)->prv->nxt = *src;
	(*src)->nxt->prv = *src;
	(*dst)->prv = *dst;
	(*dst)->nxt = *dst;
	(*dst)->prv->nxt = *dst;
	(*dst)->nxt->prv = *dst;
	return ;
}

static void	ft_push_src_1(t_node **src, t_node **dst)
{
	(*src)->nxt = *dst;
	(*src)->prv = (*dst)->prv;
	(*src)->prv->nxt = *src;
	(*src)->nxt->prv = *src;
	*dst = *src;
	*src = NULL;
	return ;
}

static void	ft_push_regular(t_node **src, t_node **dst)
{
	t_node	*tmp_prv;
	t_node	*tmp_nxt;

	tmp_prv = (*src)->prv;
	tmp_nxt = (*src)->nxt;
	(*src)->nxt = (*dst);
	(*src)->prv = (*dst)->prv;
	*dst = *src;
	*src = tmp_nxt;
	(*src)->prv = tmp_prv;
	(*src)->prv->nxt = *src;
	(*src)->nxt->prv = *src;
	(*dst)->prv->nxt = *dst;
	(*dst)->nxt->prv = *dst;
	return ;
}

void	ft_push(t_stack *from, t_stack *to)
{
	if (!from->size)
		return ;
	if (from->size == 1)
		ft_push_src_1(&from->lst, &to->lst);
	else if (to->size == 0)
		ft_push_dst_0(&from->lst, &to->lst);
	else
		ft_push_regular(&from->lst, &to->lst);
	from->size -= 1;
	to->size += 1;
	return ;
}
