/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 08:56:52 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/09 08:58:11 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*find_max_node(t_list *stack)
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
