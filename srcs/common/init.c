/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 07:38:26 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/09 11:14:20 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	init_stack(char **num_char_set, t_list **stack_a)
{
	int		num_set_size;
	int		*num_int_set;
	int		i;
	t_list	*new_node;

	num_set_size = count_set_size(num_char_set);
	num_int_set = ft_atoi_map(num_char_set);
	if (!num_int_set)
		return (FAILURE);
	i = 0;
	while (i < num_set_size)
	{
		new_node = ft_lstnew(num_int_set[i]);
		if (!new_node)
			return (free(num_int_set), FAILURE);
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
	return (free(num_int_set), SUCCESS);
}

int	init_best_move(t_best_move *best_move)
{
	if (!best_move)
		return (FAILURE);
	ft_memset(best_move, 0, sizeof(t_best_move));
	best_move->cost = INT_MAX;
	return (SUCCESS);
}

int	init_ops(t_ops *ops)
{
	if (!ops)
		return (FAILURE);
	ft_memset(ops, 0, sizeof(t_ops));
	return (SUCCESS);
}
