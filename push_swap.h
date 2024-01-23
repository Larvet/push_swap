/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:07:47 by locharve          #+#    #+#             */
/*   Updated: 2024/01/23 13:41:41 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/////////////////////////////////////////////////////////// STRUCTURES

typedef struct s_node
{
	size_t			index;
	int				nbr;
	int				cost;
	int				abs_cost;
	struct s_node	*target;
	struct s_node	*prv;
	struct s_node	*nxt;
}	t_node;

typedef struct s_stack
{
	size_t			size;
	struct s_node	*lst;
	char			name;
}	t_stack;

typedef struct s_report
{
	char			*op;
	struct s_report	*nxt;
}	t_report;

/////////////////////////////////////////////////////////// PARSING

// all_empty_strs.c
int			all_empty_strs(int ac, char **av);

// parsing.c
void		args_to_stack(t_stack *stack, int ac, char **av);

// p_list_utils.c
t_node		*new_node(int val);
void		list_clear(t_node *lst, size_t size);
void		list_add_back(t_node **prv, t_node **node, t_node *new);

// be_circular.c
size_t		list_size(t_node *node, size_t index);
t_node		*last_node(t_node *node);
void		be_circular(t_stack *stack);

// ft_split.c
void		free_all(char **split);
char		**ft_split(const char *s);

// check_fonctions.c
int			ft_isdigit(char c);
int			ft_isspace(char c);
int			ft_issign(char c);
int			is_valid_nbr(long long nbr);
int			is_valid_str(char *str);

// print_error.c
void		print_error(void);

// no_same_nbrs.c
int			no_same_nbrs(t_stack *stack);

// check_sort.c
int			check_sort(t_node *lst, size_t size);

/////////////////////////////////////////////////////////// ALGORITHM

// turk.c
t_report	*turk(t_stack *a);

// sort_three.c
t_report	*sort_three(t_stack *a, t_stack *b);

// cheapest_node.c
t_report	*cheapest_node(t_stack *from, t_stack *to);

// put_cost.c
void		evaluate_all_nodes(t_stack *stack);
void		put_cost(t_stack *from, t_stack *to);

// put_target.c
t_node		*find_min(t_stack *stack);
t_node		*find_max(t_stack *stack);
void		put_target(t_stack *from, t_stack *to);

// put_abs_cost.c
int			same_sign(int a, int b);
void		put_abs_cost(t_stack *stack);

// r_list_utils.c
t_report	*new_report(char *str);
void		report_clear(t_report *lst);
void		report_add_back(t_report **lst, t_report *new);
void		put_index(t_stack *stack);

// ft_strdup.c
size_t		ft_strlen(char *str);
char		*ft_strdup(char *src);

// fill_report.c
int			simplify_cost(t_node *node, int *cost_from, int *cost_to);
t_report	*fill_report(int cost, char name);

// write_report.c
t_report	*write_report(t_stack *from, t_stack *to, t_node *cheapest);

// execute_report.c
void		do_swap(t_stack *a, t_stack *b, char op);
void		do_push(t_stack *a, t_stack *b, char op);
void		do_rotate(t_stack *a, t_stack *b, char *op);
void		do_move(t_stack *a, t_stack *b, char *op);
void		execute_report(t_stack *a, t_stack *b, t_report *report);

// ft_swap.c
void		ft_swap(int *a, int *b);

// ft_rotate.c
void		ft_rotate(t_stack *stack, int direction);

// ft_push.c
void		ft_push(t_stack *from, t_stack *to);

// last_rotation.c
t_report	*last_rotation(t_stack *a, t_stack *b, t_report *report);

/////////////////////////////////////////////////////////// OTHERS

// ft_calloc.c
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);

// abs_val.c
int			abs_val(int n);

// print.c
void		print_error(void);
void		print_report(t_report *report);

/////////////////////////////////////////////////////////// BONUS

// ft_strcmp_bonus.c
int			ft_strcmp(char *s1, char *s2);

// get_next_line_bonus.c & get_next_line_utils_bonus.c
char		*get_next_line(int fd);
char		*ft_fill_line(char *new_l, int fd);
char		*ft_read_file(char *line, int fd);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strcut(char *src, int c);
char		*ft_strchr(char *str, int c);
char		*ft_strcat_dst(char *dst, char *s1, char *s2);

#endif
