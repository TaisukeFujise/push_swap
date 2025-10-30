/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 22:25:04 by tafujise          #+#    #+#             */
/*   Updated: 2025/10/31 01:40:10 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	stacks.stack_a.top = NULL;
	stacks.stack_a.size = 0;
	stacks.stack_b.top = NULL;
	stacks.stack_b.size = 0;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (parse_arg(argc, argv, &stacks.stack_a) == FAILURE)
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