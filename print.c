/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:10:52 by locharve          #+#    #+#             */
/*   Updated: 2024/01/18 13:43:28 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	return ;
}

void	print_report(t_report *report)
{
	if (report)
	{
		write(1, report->op, ft_strlen(report->op));
		write(1, "\n", 1);
		print_report(report->nxt);
	}
	return ;
}
