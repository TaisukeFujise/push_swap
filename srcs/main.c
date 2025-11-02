/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 22:25:04 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/03 00:44:46 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_list *stack)
{
	int	i;

	if (stack == NULL)
		return ;
	while (stack != NULL)
	{
		printf("%d\n", stack -> content);
		stack = stack -> next;
	}
}

int	main(int argc, char **argv)
{
	// t_stacks	stacks;
	t_list	*stack_a;
	// t_list	*stack_b;

	stack_a = NULL;
	// stack_b = NULL;
	if (argc < 2)
		return (EXIT_SUCCESS);
	if (parse_args(argc, argv, &stack_a) == FAILURE)
	{
		free_stack(&stack_a);
		return (print_error(), EXIT_FAILURE);
	}
	print_stack(stack_a);
	// free_stack(&stack_a);
	// ソートの実行、命令の出力
	// do_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	// free_stack(&stack_b);
	return (EXIT_SUCCESS);
}