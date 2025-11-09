/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_and_set_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:00:43 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/07 21:34:21 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_op_type	*calc_min_op_set(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int			min_cost;
	t_op_type	*min_op_type;

	min_cost = ft_min(ft_min(calc_cost_ra_rb(node, stack_a, stack_b),
				calc_cost_ra_rrb(node, stack_a, stack_b)),
			ft_min(calc_cost_rra_rb(node, stack_a, stack_b),
				calc_cost_rra_rrb(node, stack_a, stack_b)));
	min_op_type = malloc(sizeof(t_op_type) * 2);
	if (!min_op_type)
		return (NULL);
	if (calc_cost_ra_rb(node, stack_a, stack_b) == min_cost
		|| calc_cost_ra_rrb(node, stack_a, stack_b) == min_cost)
		min_op_type[0] = RA;
	else
		min_op_type[0] = RRA;
	if (calc_cost_ra_rb(node, stack_a, stack_b) == min_cost
		|| calc_cost_rra_rb(node, stack_a, stack_b) == min_cost)
		min_op_type[1] = RB;
	else
		min_op_type[1] = RRB;
	return (min_op_type);
}

void	calc_and_set_ops(t_list *node, t_list *stack_a, t_list *stack_b,
			t_ops *ops)
{
	t_op_type	*min_op_type;

	min_op_type = calc_min_op_set(node, stack_a, stack_b);
	if (!min_op_type)
		return ;
	if (min_op_type[0] == RA && min_op_type[1] == RB)
		set_ops_ra_rb(node, stack_a, stack_b, ops);
	else if (min_op_type[0] == RA && min_op_type[1] == RRB)
		set_ops_ra_rrb(node, stack_a, stack_b, ops);
	else if (min_op_type[0] == RRA && min_op_type[1] == RB)
		set_ops_rra_rb(node, stack_a, stack_b, ops);
	else
		set_ops_rra_rrb(node, stack_a, stack_b, ops);
	free(min_op_type);
}
