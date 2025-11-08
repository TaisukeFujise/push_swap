/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:12:48 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/07 20:55:05 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_ops(t_ops *ops)
{
	if (ops == NULL)
	{	
		puts("NULL");
		return ;
	}
	printf("ra: %d\n", ops->ra);
	printf("rb: %d\n", ops->rb);
	printf("rr: %d\n", ops->rr);
	printf("rra: %d\n", ops->rra);
	printf("rrb: %d\n", ops->rrb);
	printf("rrr: %d\n", ops->rrr);
}

void	print_best_move(t_best_move *best_move)
{
	printf("%s", "node:");
	print_stack(best_move->node);
	printf("cost : %d\n", best_move->cost);
	print_ops(best_move->ops);
}

void	do_sort(t_list **stack_a, t_list **stack_b)
{
	// if (ft_lstsize(stack_a) <= 5)
	// 	small_stack_sort(stack_a, stack_b);
	// else
		normal_stack_sort(stack_a, stack_b);
}

void	normal_stack_sort(t_list **stack_a, t_list **stack_b)
{
	t_best_move	best_move;

	while (is_stack_empty(*stack_a) != SUCCESS)
	{
		init_best_move(&best_move);
		calc_best_move(&best_move, *stack_a, *stack_b);
		exec_best_move(&best_move, stack_a, stack_b);
		// free(best_move.ops);
	}
	while (is_stack_empty(*stack_b) != SUCCESS)
		push_and_print(stack_a, stack_b, PA);
	return ;
}

void	init_best_move(t_best_move *best_move)
{
	best_move->node = NULL;
	best_move->cost = INT_MAX;
	best_move->ops = NULL;
}

void	init_ops(t_ops *ops)
{
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
}

void	calc_best_move(t_best_move *best_move, t_list *stack_a, t_list *stack_b)
{
	t_list	*node;
	int		cost;
	t_ops	*ops;

	node = stack_a;
	ops = (t_ops*)malloc(sizeof(t_ops));
	init_ops(ops);
	while (node != NULL)
	{
		cost = calc_cost(node, stack_a, stack_b);
		if (cost < (best_move->cost))
		{
			calc_operations(node, stack_a, stack_b, ops);
			update_best_move(best_move, node, cost, ops);
		}
		node = node->next;
	}
	return ;
}

void	update_best_move(t_best_move *best_move,t_list *node,
						int cost, t_ops *ops)
{
	best_move->node = node;
	best_move->cost = cost;
	best_move->ops = ops;
	return ;
}

void	repeat_op(t_list **stack_a, t_list **stack_b, t_op_type op, int freq)
{
	int	i;
	
	i = 0;
	// printf("freq:%d\n", freq);
	while (i < freq)
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
		else
			print_error();
		i++;
	}
}

void	exec_best_move(t_best_move *best_move, t_list **stack_a, t_list **stack_b)
{
	repeat_op(stack_a, stack_b, RA, best_move->ops->ra);
	repeat_op(stack_a, stack_b, RB, best_move->ops->rb);
	repeat_op(stack_a, stack_b, RR, best_move->ops->rr);
	repeat_op(stack_a, stack_b, RRA, best_move->ops->rra);
	repeat_op(stack_a, stack_b, RRB, best_move->ops->rrb);
	repeat_op(stack_a, stack_b, RRR, best_move->ops->rrr);
	push_and_print(stack_a, stack_b, PB);
}

// void	selection_sort(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*top_node;
// 	t_list	*second_top_node;
// 	int	i;
// 	int	size;

// 	top_node = (*stack_a);
// 	second_top_node = (*stack_a)->next;

// 	while (is_stack_sorted(*stack_a) != SUCCESS || *stack_a != NULL)
// 	{
// 		i = 0;
// 		size = ft_lstsize(*stack_a);
// 		while (i < size)
// 		{
// 			if ((top_node->content) < (second_top_node->content))
// 				swap_and_print(stack_a, stack_b, SA);
// 			rotate_and_print(stack_a, stack_b, RA);
// 			top_node = (*stack_a);
// 			second_top_node = (*stack_a)->next;
// 			i++;
// 		}
// 		push_and_print(stack_a, stack_b, PB);
// 	}
// 	while ((*stack_b) != NULL)
// 		push_and_print(stack_a, stack_b, PA);
// }
