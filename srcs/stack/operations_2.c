/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:18:10 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/06 09:18:33 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*top_node;
	t_list	*second_top_node;
	t_list	*bottom_node;

	if (stack == NULL)
		return ;
	if ((*stack) == NULL || ((*stack)->next) == NULL)
		return ;
	top_node = *stack;
	second_top_node = (*stack)->next;
	bottom_node = ft_lstlast(*stack);
	top_node->next = NULL;
	top_node->prev = bottom_node;
	second_top_node->prev = NULL;
	bottom_node->next = top_node;
	*stack = second_top_node;
	return ;
}

void	rotate_and_print(t_list **stack_a, t_list **stack_b, t_op_type op)
{
	if (op == RA)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
		return ;
	}
	else if (op == RB)
	{
		rotate(stack_b);
		write(1, "rb\n", 3);
		return ;
	}
	else if (op == RR)
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
		return ;
	}
	else
		print_error();
	return ;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*top_node;
	t_list	*second_bottom_node;
	t_list	*bottom_node;

	if (stack == NULL)
		return ;
	if ((*stack) == NULL || ((*stack)->next) == NULL)
		return ;
	top_node = *stack;
	bottom_node = ft_lstlast(*stack);
	second_bottom_node = bottom_node->prev;
	bottom_node->next = top_node;
	bottom_node->prev = NULL;
	second_bottom_node->next = NULL;
	top_node->prev = bottom_node;
	*stack = bottom_node;
	return ;
}

void	rev_rotate_and_print(t_list **stack_a, t_list **stack_b, t_op_type op)
{
	if (op == RRA)
	{
		reverse_rotate(stack_a);
		write(1, "rra\n", 4);
		return ;
	}
	else if (op == RRB)
	{
		reverse_rotate(stack_b);
		write(1, "rrb\n", 4);
		return ;
	}
	else if (op == RRR)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
		return ;
	}
	else
		print_error();
	return ;
}

