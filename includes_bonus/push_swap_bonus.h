/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:21:22 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/09 12:01:12 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../includes/push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
// checker/
// apply.c
int			apply_instruction(char *instruction,
				t_list **stack_a, t_list **stack_b);
// get_next_line.c
char		*get_next_line(int fd);
// print_result.c
void		print_ok(void);
void		print_ko(void);
#endif
