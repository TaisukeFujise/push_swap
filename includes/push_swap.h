/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 22:10:31 by tafujise          #+#    #+#             */
/*   Updated: 2025/10/31 01:36:41 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUCCESS 0
# define FAILURE -1

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				content;
	struct s_node	*next;
}	t_node;

typedef struct stack 
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_stacks
{
	t_stack	stack_a;
	t_stack	stack_b;
}	t_stacks;

#endif