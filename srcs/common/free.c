/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:10:13 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/09 12:31:27 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_num_char_set(char **num_char_set)
{
	int	i;

	i = 0;
	while (num_char_set[i])
	{
		free(num_char_set[i]);
		i++;
	}
	free(num_char_set);
}

void	free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*next;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current != NULL)
	{
		next = current -> next;
		free(current);
		current = next;
	}
	*stack = NULL;
	return ;
}

void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	return ;
}

void	free_best_move(t_best_move *best_move)
{
	if (best_move->ops != NULL)
		free(best_move->ops);
	free(best_move);
	return ;
}
