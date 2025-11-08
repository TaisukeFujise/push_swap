/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:22:49 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/09 08:03:01 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	small_stack_sort(t_list **stack_a, t_list **stack_b)
{
	int		pos;

	if (ft_lstsize(*stack_a) <= 1)
		return ;
	else if (ft_lstsize(*stack_a) == 2)
		swap_and_print(stack_a, stack_b, SA);
	else if (ft_lstsize(*stack_a) == 3)
		stack_sort_3(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 4)
	{
		pos = get_node_pos(find_min_node(*stack_a), *stack_a);
		if (pos <= ft_lstsize(*stack_a) / 2)
			repeat_rotate(stack_a, stack_b, RA, pos);
		else
			repeat_rotate(stack_a, stack_b, RRA, ft_lstsize(*stack_a) - pos);
		push_and_print(stack_a, stack_b, PB);
		stack_sort_3(stack_a, stack_b);
		push_and_print(stack_a, stack_b, PA);
	}
}

void	stack_sort_3(t_list **stack_a, t_list **stack_b)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if (first < third && third < second)
	{
		swap_and_print(stack_a, stack_b, SA);
		rotate_and_print(stack_a, stack_b, RA);
	}
	else if (second < first && first < third)
		swap_and_print(stack_a, stack_b, SA);
	else if (second < third && third < first)
		rotate_and_print(stack_a, stack_b, RA);
	else if (third < first && first < second)
		rev_rotate_and_print(stack_a, stack_b, RRA);
	else if (third < second && second < first)
	{
		swap_and_print(stack_a, stack_b, SA);
		rev_rotate_and_print(stack_a, stack_b, RRA);
	}
	else
		return ;
}
