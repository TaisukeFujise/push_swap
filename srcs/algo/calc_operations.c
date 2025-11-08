/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:00:43 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/07 21:34:21 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_list	*find_max_node(t_list *stack)
{
	t_list	*max_node;

	max_node = stack;
	while (stack != NULL)
	{
		if (stack->content > max_node->content)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

static t_list	*find_target_in_b(t_list *node_a, t_list *stack_b)
{
	t_list	*target;
	t_list	*cur_node_b;

	if (is_stack_empty(stack_b) == SUCCESS)
		return (NULL);
	target = NULL;
	cur_node_b = stack_b;
	while (cur_node_b != NULL)
	{
		if (cur_node_b->content < node_a->content)
		{
			if (target == NULL || cur_node_b->content > target->content)
				target = cur_node_b;
		}
		cur_node_b = cur_node_b->next;
	}
	if (target == NULL)
		target = find_max_node(stack_b);
	return (target);
}

void	calc_operations(t_list *node, t_list *stack_a, t_list *stack_b, t_ops *ops)
{
	int	cost_ra_rb;
	int	cost_ra_rrb;
	int	cost_rra_rb;
	int	cost_rra_rrb;

	cost_ra_rb = calc_cost_ra_rb(node, stack_a, stack_b);
	cost_ra_rrb = calc_cost_ra_rrb(node, stack_a, stack_b);
	cost_rra_rb = calc_cost_rra_rb(node, stack_a, stack_b);
	cost_rra_rrb = calc_cost_rra_rrb(node, stack_a, stack_b);
	if (cost_ra_rb <= cost_ra_rrb && cost_ra_rb <= cost_rra_rb && cost_ra_rb <= cost_rra_rrb)
	{
		ops->ra = calc_cost_ra(node, stack_a, stack_b) - calc_cost_rr(node, stack_a, stack_b);
		ops->rb = calc_cost_rb(node, stack_a, stack_b) - calc_cost_rr(node, stack_a, stack_b);
		ops->rr = calc_cost_rr(node, stack_a, stack_b);
	}
	else if (cost_ra_rrb <= cost_ra_rb && cost_ra_rrb <= cost_rra_rb && cost_ra_rrb <= cost_rra_rrb)
	{
		ops->ra = calc_cost_ra(node, stack_a, stack_b);
		ops->rrb = calc_cost_rrb(node, stack_a, stack_b);
	}
	else if (cost_rra_rb <= cost_ra_rb && cost_rra_rb <= cost_ra_rrb && cost_rra_rb <= cost_rra_rrb)
	{
		ops->rra = calc_cost_rra(node, stack_a, stack_b);
		ops->rb = calc_cost_rb(node, stack_a, stack_b);
	}
	else
	{
		ops->rra = calc_cost_rra(node, stack_a, stack_b) - calc_cost_rrr(node, stack_a, stack_b);
		ops->rrb = calc_cost_rrb(node, stack_a, stack_b) - calc_cost_rrr(node, stack_a, stack_b);
		ops->rrr = calc_cost_rrr(node, stack_a, stack_b);
	}
}

int	calc_cost_ra(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int		cost;
	t_list	*cur_node;

	(void)stack_b;
	cost = 0;
	cur_node = stack_a;
	while (cur_node != node)
	{
		cost++;
		cur_node = cur_node->next;
	}
	return (cost);
}

int	calc_cost_rb(t_list *node_a, t_list *stack_a, t_list *stack_b)
{
	int		cost;
	t_list	*target_b;
	t_list	*cur_node_b;

	(void)stack_a;
	cost = 0;
	target_b = find_target_in_b(node_a, stack_b);
	if (target_b == NULL)
		return (0);
	cur_node_b = stack_b;
	while (cur_node_b != target_b)
	{
		cost++;
		cur_node_b = cur_node_b->next;
	}
	return (cost);
}

int	calc_cost_rra(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int	cost_ra;

	(void)stack_b;
	cost_ra = calc_cost_ra(node, stack_a, stack_b);
	if (cost_ra == 0)
		return (0);
	return (ft_lstsize(stack_a) - cost_ra);
}

int	calc_cost_rrb(t_list *node_a, t_list *stack_a, t_list *stack_b)
{
	int	cost_rb;

	(void)stack_a;
	cost_rb = calc_cost_rb(node_a, stack_a, stack_b);
	if (cost_rb == 0)
		return (0);
	return (ft_lstsize(stack_b) - cost_rb);
}
