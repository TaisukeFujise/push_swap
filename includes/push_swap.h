/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 22:10:31 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/08 23:02:31 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUCCESS 0
# define FAILURE -1

# include "../libft/libft.h"
# include <fcntl.h>

# define MIN(Value1, Value2) (((Value1) < (Value2)) ? (Value1) : (Value2))
# define MAX(Value1, Value2) (((Value1) > (Value2)) ? (Value1) : (Value2))
/*bonus*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1056
# endif

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef enum e_op_type
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_op_type;

typedef struct s_ops
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_ops;

typedef struct s_best_move
{
	t_list			*node;
	int				cost;
	t_ops			*ops;
}	t_best_move;

// print_error.c
void	print_error(void);
// parse_args.c
int		parse_args(int argc, char **argv, t_list **stack_a);
//check_error.c
int		check_error(char **num_char_set);
int		check_digit(char **num_char_set);
int		check_int_limits(char **num_char_set);
int		check_duplicates(char **num_char_set);
// limits.c
int		is_in_int_min(char *num_str);
int		is_in_int_max(char *num_str);
int		is_in_int_limits(char *num_str);
// free.c
void	free_num_char_set(char **num_char_set);
void	free_stack(t_list **stack);
void	free_stacks(t_list **stack_a, t_list **stack_b);
// utils.c
char	**ft_str_arr_dup(char **str_arr);
int		count_set_size(char **num_char_set);
int		*ft_atoi_map(char **num_char_set);
int		is_stack_sorted(t_list *stack);
int		is_stack_empty(t_list *stack);
// list.c
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
// init.c
int		init_stack(char **num_char_set, t_list **stack_a);
void	init_best_move(t_best_move *best_move);
void	init_ops(t_ops *ops);
// sort.c
void	do_sort(t_list **stack_a, t_list **stack_b);
void	main_stack_sort(t_list **stack_a, t_list **stack_b);
void	init_best_move(t_best_move *best_move);
void	init_ops(t_ops *ops);
t_best_move	*calc_best_move(t_list *stack_a, t_list *stack_b);
void	repeat_rotate(t_list **stack_a, t_list **stack_b, t_op_type op, int freq);
void	exec_best_move(t_best_move *best_move, t_list **stack_a, t_list **stack_b);
t_list	*find_min_node(t_list *stack);
int	get_node_pos(t_list *node, t_list *stack);

// small_stack_sort.c
void	small_stack_sort(t_list **stack_a, t_list **stack_b);
void	stack_sort_3(t_list **stack_a, t_list **stack_b);

// calc_cost.c
int		calc_cost(t_list *node, t_list *stack_a, t_list *stack_b);
int		calc_cost_ra_rb(t_list *node, t_list *stack_a, t_list *stack_b);
int		calc_cost_ra_rrb(t_list *node, t_list *stack_a, t_list *stack_b);
int		calc_cost_rra_rb(t_list *node, t_list *stack_a, t_list *stack_b);
int		calc_cost_rra_rrb(t_list *node, t_list *stack_a, t_list *stack_b);
int		calc_cost_rr(t_list *node, t_list *stack_a, t_list *stack_b);
int		calc_cost_rrr(t_list *node, t_list *stack_a, t_list *stack_b);
// calc_operations.c
void	calc_operations(t_list *node, t_list *stack_a, t_list *stack_b, t_ops *ops);
int		calc_cost_ra(t_list *node, t_list *stack_a, t_list *stack_b);
int		calc_cost_rb(t_list *node, t_list *stack_a, t_list *stack_b);
int		calc_cost_rra(t_list *node, t_list *stack_a, t_list *stack_b);
int		calc_cost_rrb(t_list *node, t_list *stack_a, t_list *stack_b);


// operations_1.c
void	swap(t_list **stack);
void	swap_and_print(t_list **stack_a, t_list **stack_b, t_op_type op);
void	push(t_list **stack_from, t_list **stack_to);
void	push_and_print(t_list **stack_a, t_list **stack_b, t_op_type op);
// operations_2.c
void	rotate(t_list **stack);
void	rotate_and_print(t_list **stack_a, t_list **stack_b, t_op_type op);
void	reverse_rotate(t_list **stack);
void	rev_rotate_and_print(t_list **stack_a, t_list **stack_b, t_op_type op);

//bonus
// get_next_line.c
char	*get_next_line(int fd);
// apply.c
int	apply_instruction(char *instruction, t_list **stack_a, t_list **stack_b);
// print_result.c
void	print_ok(void);
void	print_ko(void);
// test用関数
void	print_stack(t_list *stack);
void	print_best_move(t_best_move *best_move);
void	print_ops(t_ops *ops);
#endif
