/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:05:54 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/09 11:14:09 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	main_stack_sort(t_list **stack_a, t_list **stack_b)
{
	t_best_move	*best_move;
	int			pos;

	while (is_stack_empty(*stack_a) == FAILURE)
	{
		best_move = calc_best_move(*stack_a, *stack_b);
		if (!best_move)
			return ;
		exec_best_move(best_move, stack_a, stack_b);
		free(best_move->ops);
		free(best_move);
		best_move = NULL;
		best_move = NULL;
	}
	pos = get_node_pos(find_min_node(*stack_b), *stack_b);
	if (pos <= ft_lstsize(*stack_b) / 2)
		repeat_rotate(stack_a, stack_b, RB, pos + 1);
	else
		repeat_rotate(stack_a, stack_b, RRB, ft_lstsize(*stack_b) - pos - 1);
	while (is_stack_empty(*stack_b) == FAILURE)
		push_and_print(stack_a, stack_b, PA);
}

t_best_move	*calc_best_move(t_list *stack_a, t_list *stack_b)
{
	t_best_move	*best_move;
	t_ops		*ops;
	t_list		*node;
	int			cost;

	best_move = (t_best_move *)malloc(sizeof(t_best_move));
	if (init_best_move(best_move) == FAILURE)
		return (NULL);
	ops = (t_ops *)malloc(sizeof(t_ops));
	if (init_ops(ops) == FAILURE)
		return (free(best_move), NULL);
	node = stack_a;
	while (node != NULL)
	{
		init_ops(ops);
		cost = calc_cost(node, stack_a, stack_b);
		if (cost < best_move->cost)
		{
			calc_and_set_ops(node, stack_a, stack_b, ops);
			if (update_best_move(best_move, node, ops, cost) == FAILURE)
				return (free(ops), free_best_move(best_move), NULL);
		}
		node = node->next;
	}
	return (free(ops), best_move);
}

int	update_best_move(t_best_move *best_move, t_list *node, t_ops *ops, int cost)
{
	if (!best_move->ops)
	{
		best_move->ops = (t_ops *)malloc(sizeof(t_ops));
		if (!best_move->ops)
			return (FAILURE);
	}
	ft_memcpy(best_move->ops, ops, sizeof(t_ops));
	best_move->node = node;
	best_move->cost = cost;
	return (SUCCESS);
}

void	exec_best_move(t_best_move *best_move,
			t_list **stack_a, t_list **stack_b)
{
	if (!best_move || !best_move->ops)
		return ;
	repeat_rotate(stack_a, stack_b, RA, best_move->ops->ra);
	repeat_rotate(stack_a, stack_b, RB, best_move->ops->rb);
	repeat_rotate(stack_a, stack_b, RR, best_move->ops->rr);
	repeat_rotate(stack_a, stack_b, RRA, best_move->ops->rra);
	repeat_rotate(stack_a, stack_b, RRB, best_move->ops->rrb);
	repeat_rotate(stack_a, stack_b, RRR, best_move->ops->rrr);
	push_and_print(stack_a, stack_b, PB);
}
