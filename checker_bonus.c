/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:05:37 by locharve          #+#    #+#             */
/*   Updated: 2024/01/23 13:46:28 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_cmd(char *str)
{
	if (!ft_strcmp("sa", str) || !ft_strcmp("sb", str)
		|| !ft_strcmp("ss", str) || !ft_strcmp("ra", str)
		|| !ft_strcmp("rb", str) || !ft_strcmp("rr", str)
		|| !ft_strcmp("rra", str) || !ft_strcmp("rrb", str)
		|| !ft_strcmp("rrr", str) || !ft_strcmp("pa", str)
		|| !ft_strcmp("pb", str))
		return (1);
	else
		return (0);
}

static void	invalid_cmd_procedure(t_report **report, char **str)
{
	report_clear(*report);
	*report = NULL;
	free(*str);
	close(0);
	*str = get_next_line(0);
	free(*str);
}

static t_report	*read_input(void)
{
	t_report	*report;
	t_report	*tmp;
	char		*str;

	report = NULL;
	str = get_next_line(0);
	while (str)
	{
		if (is_valid_cmd(str))
		{
			tmp = new_report(str);
			if (tmp)
				report_add_back(&report, tmp);
		}
		else
			print_error();
		if (!is_valid_cmd(str) || !tmp)
		{
			invalid_cmd_procedure(&report, &str);
			break ;
		}
		free(str);
		str = get_next_line(0);
	}
	return (report);
}

static void	init_stack(t_stack *stack, char c)
{
	ft_bzero(stack, sizeof(*stack));
	stack->name = c;
	return ;
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_report	*report;

	if (argc <= 1)
		return (0);
	init_stack(&a, 'a');
	args_to_stack(&a, argc - 1, &argv[1]);
	if (a.lst)
	{
		init_stack(&b, 'b');
		report = read_input();
		if (report)
		{
			execute_report(&a, &b, report);
			if (check_sort(a.lst, a.size))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
			report_clear(report);
		}
	}
	list_clear(a.lst, a.size);
	return (0);
}
