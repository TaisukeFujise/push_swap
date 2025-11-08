/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:00:43 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/07 08:53:50 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//debug
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
	if (cost_ra_rb == calc_cost(node, stack_a, stack_b))
	{
		ops->ra = calc_cost_ra(node, stack_a, stack_b) - calc_cost_rr(node, stack_a, stack_b);
		ops->rb = calc_cost_rb(node, stack_a, stack_b) - calc_cost_rr(node, stack_a, stack_b);
		ops->rr = calc_cost_rr(node, stack_a, stack_b);
	}
	else if (cost_ra_rrb == calc_cost(node, stack_a, stack_b))
	{
		ops->ra = calc_cost_ra(node, stack_a, stack_b);
		ops->rrb = calc_cost_rrb(node, stack_a, stack_b);
	}
	else if (cost_rra_rb == calc_cost(node, stack_a, stack_b))
	{
		ops->rra = calc_cost_rra(node, stack_a, stack_b);
		ops->rb = calc_cost_rb(node, stack_a, stack_b);
	}
	else if (cost_rra_rrb == calc_cost(node, stack_a, stack_b))
	{
		ops->rra = calc_cost_rra(node, stack_a, stack_b) - calc_cost_rrr(node, stack_a, stack_b);
		ops->rrb = calc_cost_rrb(node, stack_a, stack_b) - calc_cost_rrr(node, stack_a, stack_b);
		ops->rrr = calc_cost_rrr(node, stack_a, stack_b);
	}
	else
		print_error();
	return ;
}

int	calc_cost_ra(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int	cost;
	
	cost = 0;
	node = node->prev;
	while (node != NULL)
	{
		cost++;
		node = node->prev;
	}
	return (cost);
}

int	calc_cost_rb(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int	cost;
	t_list	*node_b;

	cost = 0;
	if (ft_lstsize(stack_b) < 2)
		return (cost);
	if (((ft_lstlast(stack_b)->content) < node->content) 
		&& (node-> content < (stack_b->content)))
		return (cost);
	node_b = stack_b;
	while (node_b != NULL)
	{
		cost++;
		if (node_b->next == NULL)
			break;
		if ((node_b->content < node->content)
			&&(node->content < node_b->next->content))
			return (cost);
		node_b = node_b->next;
	}
	return (cost);
}

int	calc_cost_rra(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int	cost;

	cost = 0;
	if (node->prev == NULL)
		return (cost);
	while (node != NULL)
	{
		cost++;
		node = node->next;
	}
	return (cost);
}

int	calc_cost_rrb(t_list *node, t_list *stack_a, t_list *stack_b)
{
	int		cost;
	t_list	*node_b;

	cost = 0;
	if (ft_lstsize(stack_b) < 2)
		return (cost);
	if ((ft_lstlast(stack_b)->content < node->content)
		&& (node->content < stack_b->content))
		return (cost);
	node_b = ft_lstlast(stack_b);
	while (node_b != NULL)
	{
		cost++;
		if (node_b->prev == NULL)
			break;
		if ((node_b->content < node->content)
			&& (node->content < node_b->prev->content))
			return (cost);
		node_b = node_b->prev;
	}
	return (cost);
}
