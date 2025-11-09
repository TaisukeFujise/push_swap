/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:32:37 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/09 11:48:11 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/push_swap_bonus.h"

int	apply_instruction(char *instruction, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(instruction, "sa\n") == 0)
		return (swap(stack_a), SUCCESS);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		return (swap(stack_b), SUCCESS);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		return (swap(stack_a), swap(stack_b), SUCCESS);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		return (push(stack_b, stack_a), SUCCESS);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		return (push(stack_a, stack_b), SUCCESS);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		return (rotate(stack_a), SUCCESS);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		return (rotate(stack_b), SUCCESS);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		return (rotate(stack_a), rotate(stack_b), SUCCESS);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		return (reverse_rotate(stack_a), SUCCESS);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		return (reverse_rotate(stack_b), SUCCESS);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		return (reverse_rotate(stack_a), reverse_rotate(stack_b), SUCCESS);
	else
		return (FAILURE);
}
