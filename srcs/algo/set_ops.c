/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 09:56:31 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/09 09:58:36 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_ops_ra_rb(t_list *node, t_list *stack_a, t_list *stack_b,
					t_ops *ops)
{
	int	cost_ra;
	int	cost_rb;
	int	cost_rr;

	cost_ra = calc_cost_ra(node, stack_a, stack_b);
	cost_rb = calc_cost_rb(node, stack_a, stack_b);
	cost_rr = calc_cost_rr(node, stack_a, stack_b);
	ops->ra = cost_ra - cost_rr;
	ops->rb = cost_rb - cost_rr;
	ops->rr = cost_rr;
}

void	set_ops_ra_rrb(t_list *node, t_list *stack_a, t_list *stack_b,
					t_ops *ops)
{
	int	cost_ra;
	int	cost_rrb;

	cost_ra = calc_cost_ra(node, stack_a, stack_b);
	cost_rrb = calc_cost_rrb(node, stack_a, stack_b);
	ops->ra = cost_ra;
	ops->rrb = cost_rrb;
}

void	set_ops_rra_rb(t_list *node, t_list *stack_a, t_list *stack_b,
					t_ops *ops)
{
	int	cost_rra;
	int	cost_rb;

	cost_rra = calc_cost_rra(node, stack_a, stack_b);
	cost_rb = calc_cost_rb(node, stack_a, stack_b);
	ops->rra = cost_rra;
	ops->rb = cost_rb;
}

void	set_ops_rra_rrb(t_list *node, t_list *stack_a, t_list *stack_b,
					t_ops *ops)
{
	int	cost_rra;
	int	cost_rrb;
	int	cost_rrr;

	cost_rra = calc_cost_rra(node, stack_a, stack_b);
	cost_rrb = calc_cost_rrb(node, stack_a, stack_b);
	cost_rrr = calc_cost_rrr(node, stack_a, stack_b);
	ops->rra = cost_rra - cost_rrr;
	ops->rrb = cost_rrb - cost_rrr;
	ops->rrr = cost_rrr;
}
