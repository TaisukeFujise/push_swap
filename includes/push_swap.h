/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 22:10:31 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/04 07:24:31 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUCCESS 0
# define FAILURE -1

# include "../libft/libft.h"
# include <stdio.h>

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
// utils.c
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_str_arr_dup(char **str_arr);
int		count_set_size(char **num_char_set);
int		*ft_atoi_map(char **num_char_set);
// list.c
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
// init.c
int		init_stack(char **num_char_set, t_list **stack_a);
// sort.c
void	do_sort(t_list **stack_a, t_list **stack_b);
// operations.c
void	swap(t_list **stack);
void	push(t_list **stack_from, t_list **stack_to);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

#endif