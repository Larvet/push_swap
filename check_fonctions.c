/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fonctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:15:37 by locharve          #+#    #+#             */
/*   Updated: 2023/12/17 18:05:05 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_issign(char c)
{
	if (c == 43)
		return (1);
	else if (c == 45)
		return (-1);
	else
		return (0);
}

int	is_valid_nbr(long long nbr)
{
	if (nbr >= -2147483648 && nbr <= 2147483647)
		return (1);
	else
		return (0);
}

int	is_valid_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_issign(str[i]) && ((i > 0 && !ft_isspace(str[i - 1]))
				|| !ft_isdigit(str[i + 1])))
			return (0);
		if (!ft_issign(str[i]) && !ft_isspace(str[i]) && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
