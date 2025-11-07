/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 04:38:01 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/06 09:23:26 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list **stack)
{
	t_list	*top_node;
	t_list	*second_top_node;

	if (stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	top_node = (*stack);
	second_top_node = (*stack)->next;
	top_node->prev = second_top_node;
	top_node->next = second_top_node->next;
	second_top_node->next = top_node;
	second_top_node->prev = NULL;
	*stack = second_top_node;
	if (top_node->next != NULL)
		(top_node->next)->prev = top_node;
	return ;
}

void	swap_and_print(t_list **stack_a, t_list **stack_b, t_op_type op)
{
	if (op == SA)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
		return ;
	}
	else if (op == SB)
	{
		swap(stack_b);
		write(1, "sb\n", 3);
		return ;
	}
	else if (op == SS)
	{
		swap(stack_a);
		swap(stack_b);
		write(1, "ss\n", 3);
		return ;
	}
	else
		print_error();
	return ;
}

void	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*stack_from_first;
	t_list	*stack_from_second;

	if (stack_from == NULL || stack_to == NULL)
		return ;
	if ((*stack_from) == NULL)
		return ;
	stack_from_first = *stack_from;
	stack_from_second = (*stack_from)->next;
	if (stack_from_second != NULL)
		stack_from_second->prev = NULL;
	stack_from_first->prev = NULL;
	stack_from_first->next = *stack_to;
	if ((*stack_to) != NULL)
		(*stack_to)->prev = stack_from_first;
	*stack_from = stack_from_second;
	*stack_to = stack_from_first;
	return ;
}

void	push_and_print(t_list **stack_a, t_list **stack_b, t_op_type op)
{
	if (op == PA)
	{
		push(stack_b, stack_a);
		write(1, "pa\n", 3);
		return ;
	}
	else if (op == PB)
	{
		push(stack_a, stack_b);
		write(1, "pb\n", 3);
		return ;
	}
	else
		print_error();
	return ;
}
