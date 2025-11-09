/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:02:50 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/09 10:04:49 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	repeat_rotate(t_list **stack_a, t_list **stack_b,
			t_op_type op, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (op == RA)
			rotate_and_print(stack_a, stack_b, RA);
		else if (op == RB)
			rotate_and_print(stack_a, stack_b, RB);
		else if (op == RR)
			rotate_and_print(stack_a, stack_b, RR);
		else if (op == RRA)
			rev_rotate_and_print(stack_a, stack_b, RRA);
		else if (op == RRB)
			rev_rotate_and_print(stack_a, stack_b, RRB);
		else if (op == RRR)
			rev_rotate_and_print(stack_a, stack_b, RRR);
		i++;
	}
}
