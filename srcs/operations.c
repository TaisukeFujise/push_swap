/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 04:38:01 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/04 09:54:49 by tafujise         ###   ########.fr       */
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

// debag
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
