/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:47:57 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/07 09:09:36 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calc_cost(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int	cost_rr;
	int	cost_rrr;

	cost_rr = calc_cost_rr(node, stack_a, stack_b);
	cost_rrr = calc_cost_rrr(node, stack_a, stack_b);
	return (MIN(cost_rr, cost_rrr));
}

int	calc_cost_rr(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int	cost_ra;
	int	cost_rb;

	cost_ra = calc_cost_ra(node, stack_a, stack_b);
	cost_rb = calc_cost_rb(node, stack_a, stack_b);
	return ((cost_ra + cost_rb));
}

int	calc_cost_rrr(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int	cost_rra;
	int	cost_rrb;

	cost_rra = calc_cost_rra(node, stack_a, stack_b);
	cost_rrb = calc_cost_rrb(node, stack_a, stack_b);
	return ((cost_rra + cost_rrb));
}
