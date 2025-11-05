/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:12:48 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/04 19:09:16 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*divide sort function and print function */
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
			{
				swap(stack_a);
				puts("sa");
			}
			rotate(stack_a);
			puts("ra");
			top_node = (*stack_a);
			second_top_node = (*stack_a)->next;
			i++;
		}
		puts("pb");
		push(stack_a, stack_b);
	}
	while ((*stack_b) != NULL)
	{
		puts("pa");
		push(stack_b, stack_a);
	}
}
