/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 22:25:04 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/02 08:22:17 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (parse_args(argc, argv, &stacks.stack_a) == FAILURE)
	{
		free_stack(&stacks.stack_a);
		return (print_error(), EXIT_FAILURE);
	}
	// ソートの実行、命令の出力
	do_sort(&stacks.stack_a);
	free_stack(&stacks.stack_a);
	free_stack(&stacks.stack_b);
	return (EXIT_SUCCESS);
}