/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:47:57 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/07 19:14:06 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calc_cost(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int	cost_ra_rb;
	int	cost_ra_rrb;
	int	cost_rra_rb;
	int	cost_rra_rrb;

	cost_ra_rb = calc_cost_ra_rb(node, stack_a, stack_b);
	cost_ra_rrb = calc_cost_ra_rrb(node, stack_a, stack_b);
	cost_rra_rb = calc_cost_rra_rb(node, stack_a, stack_b);
	cost_rra_rrb = calc_cost_rra_rrb(node, stack_a, stack_b);
	return (MIN(MIN(cost_ra_rb, cost_ra_rrb), MIN(cost_rra_rb, cost_rra_rrb)));
}

int	calc_cost_ra_rb(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int	cost_ra;
	int	cost_rb;

	cost_ra = calc_cost_ra(node, stack_a, stack_b);
	cost_rb = calc_cost_rb(node, stack_a, stack_b);

	return (MAX(cost_ra, cost_rb));
}

int	calc_cost_ra_rrb(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int	cost_ra;
	int	cost_rrb;

	cost_ra = calc_cost_ra(node, stack_a, stack_b);
	cost_rrb = calc_cost_rrb(node, stack_a, stack_b);
	return (cost_ra + cost_rrb);
}

int	calc_cost_rra_rb(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int	cost_rra;
	int	cost_rb;

	cost_rra = calc_cost_rra(node, stack_a, stack_b);
	cost_rb = calc_cost_rb(node, stack_a, stack_b);
	return (cost_rra + cost_rb);
}

int	calc_cost_rra_rrb(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int	cost_rra;
	int	cost_rrb;

	cost_rra = calc_cost_rra(node, stack_a, stack_b);
	cost_rrb = calc_cost_rrb(node, stack_a, stack_b);
	return (MAX(cost_rra, cost_rrb));
}


int	calc_cost_rr(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int	cost_ra;
	int	cost_rb;

	cost_ra = calc_cost_ra(node, stack_a, stack_b);
	cost_rb = calc_cost_rb(node, stack_a, stack_b);
	return (MIN(cost_ra, cost_rb));
}

int	calc_cost_rrr(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int	cost_rra;
	int	cost_rrb;

	cost_rra = calc_cost_rra(node, stack_a, stack_b);
	cost_rrb = calc_cost_rrb(node, stack_a, stack_b);
	return (MIN(cost_rra, cost_rrb));
}
