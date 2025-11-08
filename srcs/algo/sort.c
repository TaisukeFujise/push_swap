/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:12:48 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/08 23:09:39 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*find_min_node(t_list *stack)
{
	t_list	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	while (stack != NULL)
	{
		if (stack->content < min_node->content)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

int	get_node_pos(t_list *node, t_list *stack)
{
	int		pos;

	pos = 0;
	while (stack != NULL && stack != node)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	do_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 4)
		small_stack_sort(stack_a, stack_b);
	else
	main_stack_sort(stack_a, stack_b);
}

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
	t_ops	*ops;
	t_list	*node;
	int		cost;

	best_move = (t_best_move *)malloc(sizeof(t_best_move));
	if (!best_move)
		return (NULL);
	init_best_move(best_move);
	ops = (t_ops*)malloc(sizeof(t_ops));
	if (!ops)
		return (free(best_move), NULL);
	init_ops(ops);
	node = stack_a;
	while (node != NULL)
	{
		init_ops(ops);
		cost = calc_cost(node, stack_a, stack_b);
		if (cost < best_move->cost)
		{
			calc_operations(node, stack_a, stack_b, ops);
			if (!best_move->ops)
			{
				best_move->ops = (t_ops*)malloc(sizeof(t_ops));
				if (!best_move->ops)
					return (free(ops), free(best_move), NULL);
			}
			ft_memcpy(best_move->ops, ops, sizeof(t_ops));
			best_move->node = node;
			best_move->cost = cost;
		}
		node = node->next;
	}
	free(ops);
	return (best_move);
}

void	repeat_rotate(t_list **stack_a, t_list **stack_b, t_op_type op, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (op == RA)
			rotate_and_print(stack_a, stack_b, RA);
		else if (op == RB)
			rotate_and_print(stack_a, stack_b, RB);
		else if (op == RR)
			rotate_and_print(stack_a, stack_b, RR);
		else if (op == RRA)
			rev_rotate_and_print(stack_a, stack_b, RRA);
		else if (op == RRB)
			rev_rotate_and_print(stack_a, stack_b, RRB);
		else if (op == RRR)
			rev_rotate_and_print(stack_a, stack_b, RRR);
		i++;
	}
}

void	exec_best_move(t_best_move *best_move, t_list **stack_a, t_list **stack_b)
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
