NAME=push_swap
NAMEBONUS=checker
CC=cc
SRCS=abs_val.c						\
		all_empty_strs.c			\
		be_circular.c				\
		cheapest_node.c				\
		check_fonctions.c			\
		check_sort.c				\
		execute_report.c			\
		fill_report.c				\
		ft_calloc.c					\
		ft_push.c					\
		ft_rotate.c					\
		ft_split.c					\
		ft_strdup.c					\
		ft_swap.c					\
		last_rotation.c				\
		main.c						\
		no_same_nbrs.c				\
		parsing.c					\
		p_list_utils.c				\
		print.c						\
		put_abs_cost.c				\
		put_cost.c					\
		put_target.c				\
		r_list_utils.c				\
		sort_three.c				\
		turk.c						\
		write_report.c
SRCSBONUS= checker_bonus.c			\
		get_next_line_bonus.c		\
		get_next_line_utils_bonus.c	\
		ft_strcmp_bonus.c			\
		parsing.c					\
		p_list_utils.c				\
		be_circular.c				\
		ft_split.c					\
		check_fonctions.c			\
		ft_calloc.c					\
		r_list_utils.c				\
		execute_report.c			\
		ft_strdup.c					\
		ft_swap.c					\
		ft_push.c					\
		ft_rotate.c					\
		check_sort.c				\
		print.c
HEADER=push_swap.h
OBJS=$(SRCS:.c=.o)
OBJSBONUS=$(SRCSBONUS:.c=.o)
CFLAGS=-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(NAMEBONUS)

$(NAMEBONUS): $(OBJSBONUS)
	$(CC) $(CFLAGS) $(OBJSBONUS) -o $(NAMEBONUS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -f $(NAME) $(NAMEBONUS)

clean:
	rm -f $(OBJS) $(OBJSBONUS)

re: fclean all

.PHONY: all fclean clean re
