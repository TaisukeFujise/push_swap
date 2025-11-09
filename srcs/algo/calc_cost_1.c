/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 08:07:16 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/09 09:01:57 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
	t_list	*cur_node_b;

	cost = 0;
	cur_node_b = stack_b;
	if ((ft_lstsize(stack_b) < 2) || ((cur_node_b->content < node_a->content)
			&& (node_a->content < ft_lstlast(stack_b)->content)))
		return (cost);
	if ((cur_node_b == find_max_node(stack_b))
		&& (node_a->content < ft_lstlast(stack_b)->content))
		return (cost);
	if (node_a->content < find_min_node(stack_b)->content)
		return (get_node_pos(find_min_node(stack_b), stack_b) + 1);
	if (node_a->content > find_max_node(stack_b)->content)
		return (get_node_pos(find_max_node(stack_b), stack_b));
	while (cur_node_b != NULL)
	{
		cost++;
		if ((cur_node_b->next == NULL)
			|| ((cur_node_b->next->content < node_a->content)
				&& (node_a->content < cur_node_b->content)))
			break ;
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
