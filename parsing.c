/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:14:15 by locharve          #+#    #+#             */
/*   Updated: 2024/01/14 15:59:00 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	ft_atoll(char *str)
{
	long long	result;
	int			i;
	int			sign;

	result = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = ft_issign(str[i]);
	if (sign)
		i++;
	while (ft_isdigit(str[i]))
	{
		result = str[i] - 48 + result * 10;
		i++;
	}
	if (sign)
		result *= sign;
	return (result);
}

static t_node	*strs_to_node(char **strs)
{
	t_node		*tmp;
	t_node		*node;
	long long	nbr;
	int			i;

	node = NULL;
	i = 0;
	while (strs[i])
	{
		nbr = ft_atoll(strs[i]);
		tmp = new_node((int)nbr);
		if (is_valid_str(strs[i]) && is_valid_nbr(nbr) && tmp)
			list_add_back(&node, &node, tmp);
		else
		{
			list_clear(node, list_size(node, 0));
			node = NULL;
			free(tmp);
			break ;
		}
		i++;
	}
	return (node);
}

static t_node	*arg_to_node(char *str)
{
	t_node	*node;
	char	**tmp;

	if (!str)
		return (NULL);
	node = NULL;
	tmp = ft_split((const char *)str);
	if (tmp)
	{
		node = strs_to_node(tmp);
		free_all(tmp);
	}
	return (node);
}

void	args_to_stack(t_stack *stack, int ac, char **av)
{
	t_node	*node;
	int		i;

	i = 0;
	while (i < ac)
	{
		if (av[i][0])
		{
			node = arg_to_node(av[i]);
			if (!node)
			{
				list_clear(stack->lst, stack->size);
				stack->lst = NULL;
				print_error();
				return ;
			}
			else
				list_add_back(&stack->lst, &stack->lst, node);
			stack->size += 1;
		}
		i++;
	}
	be_circular(stack);
	stack->name = 'a';
	return ;
}
