/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:50:34 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/05 23:53:11 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*instruction;

	stack_a = NULL;
	stack_b = NULL;
	instruction = NULL;
	if (argc < 2)
		return (0);
	if (parse_args(argc, argv, &stack_a) == FAILURE)
		return (print_error(), 1);
	instruction = get_next_line(0);
	while (instruction)
	{
		if (apply_instruction(instruction, &stack_a, &stack_b) == FAILURE)
			return (print_error(), free_stacks(&stack_a, &stack_b), -1);
		free(instruction);
		instruction = get_next_line(0);
	}
	if ((is_stack_sorted(stack_a) == FAILURE)
		|| (is_stack_empty(stack_b) == FAILURE))
		return (print_ko(), free_stacks(&stack_a, &stack_b), 1);
	free_stacks(&stack_a, &stack_b);
	return (print_ok(), 0);
}
