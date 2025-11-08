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

