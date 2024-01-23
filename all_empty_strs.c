/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_empty_strs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:26:52 by locharve          #+#    #+#             */
/*   Updated: 2024/01/22 16:38:15 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	all_empty_strs(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac && av[i][0])
		i++;
	if (i == ac)
		return (0);
	else
	{
		print_error();
		return (1);
	}
}
