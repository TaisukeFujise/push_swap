/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 22:10:31 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/05 23:23:44 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUCCESS 0
# define FAILURE -1

# include "../libft/libft.h"
# include <fcntl.h>
//test用
# include <stdio.h>

// bonus
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1056
# endif

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

// typedef struct s_stacks
// {
// 	t_list	stack_a;
// 	t_list	stack_b;
// }	t_stacks;

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
// sort.c
void	selection_sort(t_list **stack_a, t_list **stack_b);
// instructions.c
void	swap(t_list **stack);
void	push(t_list **stack_from, t_list **stack_to);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
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
#endif
