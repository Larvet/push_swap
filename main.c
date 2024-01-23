/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:26:48 by locharve          #+#    #+#             */
/*   Updated: 2024/01/22 16:40:21 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_report	*choose_sort(t_stack *stack)
{
	t_report	*report;

	if (stack->size == 2)
		report = new_report("sa");
	else if (stack->size == 3)
		report = sort_three(stack, NULL);
	else
		report = turk(stack);
	return (report);
}

int	main(int argc, char **argv)
{
	t_stack		stack;
	t_report	*report;

	ft_bzero(&stack, sizeof(stack));
	stack.name = 'a';
	if (argc == 1 || all_empty_strs(argc -1, &argv[1]))
		return (0);
	args_to_stack(&stack, argc - 1, &argv[1]);
	if (stack.lst)
	{
		if (!no_same_nbrs(&stack))
			print_error();
		else if (!check_sort(stack.lst, stack.size))
		{
			report = choose_sort(&stack);
			if (report)
			{
				print_report(report);
				report_clear(report);
			}
		}
		list_clear(stack.lst, stack.size);
	}
	return (0);
}
