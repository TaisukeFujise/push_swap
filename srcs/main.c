/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 22:25:04 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/05 20:09:53 by tafujise         ###   ########.fr       */
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
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (EXIT_SUCCESS);
	if (parse_args(argc, argv, &stack_a) == FAILURE)
		return (print_error(), EXIT_FAILURE);
	if (is_stack_sorted(stack_a) == SUCCESS)
		return (free_stacks(&stack_a, &stack_b), EXIT_SUCCESS);
	selection_sort(&stack_a, &stack_b);
	print_stack(stack_a);
	free_stacks(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
