/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 22:10:31 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/02 08:18:36 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUCCESS 0
# define FAILURE -1

# include "../libft/libft.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_stacks
{
	t_list	stack_a;
	t_list	stack_b;
}	t_stacks;

int	parse_args(int argc, char **argv, t_list **stack_a);


#endif