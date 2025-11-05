/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:09:16 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/05 09:38:07 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	parse_args(int argc, char **argv, t_list **stack_a)
{
	char	**num_char_set;

	if (argc == 2)
		num_char_set = ft_split(argv[1], ' ');
	else
		num_char_set = ft_str_arr_dup(&(argv[1]));
	if (!num_char_set)
		return (FAILURE);
	if (check_error(num_char_set) == FAILURE)
		return (free_num_char_set(num_char_set), FAILURE);
	if (init_stack(num_char_set, stack_a) == FAILURE)
		return (free_num_char_set(num_char_set), FAILURE);
	return (free_num_char_set(num_char_set), SUCCESS);
}
