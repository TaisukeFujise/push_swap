/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:12:48 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/06 09:24:09 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	selection_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_node;
	t_list	*second_top_node;
	int	i;
	int	size;

	top_node = (*stack_a);
	second_top_node = (*stack_a)->next;

	while (is_stack_sorted(*stack_a) != SUCCESS || *stack_a != NULL)
	{
		i = 0;
		size = ft_lstsize(*stack_a);
		while (i < size)
		{
			if ((top_node->content) < (second_top_node->content))
				swap_and_print(stack_a, stack_b, SA);
			rotate_and_print(stack_a, stack_b, RA);
			top_node = (*stack_a);
			second_top_node = (*stack_a)->next;
			i++;
		}
		push_and_print(stack_a, stack_b, PB);
	}
	while ((*stack_b) != NULL)
		push_and_print(stack_a, stack_b, PA);
}
