/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 07:32:05 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/08 23:04:37 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_error(char **num_char_set)
{
	if ((check_digit(num_char_set) == FAILURE)
		|| (check_int_limits(num_char_set) == FAILURE)
		|| (check_duplicates(num_char_set) == FAILURE))
		return (FAILURE);
	return (SUCCESS);
}

int	check_digit(char **num_char_set)
{
	int	i;
	int	j;

	i = 0;
	while (num_char_set[i])
	{
		j = 0;
		while (num_char_set[i][j])
		{
			if (!ft_isdigit(num_char_set[i][j]) && num_char_set[i][j] != '-')
			{
				write(1, "digit error", 11);
				return (FAILURE);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_int_limits(char **num_char_set)
{
	int	i;

	i = 0;
	while (num_char_set[i])
	{
		if (!is_in_int_limits(num_char_set[i]))
		{
			write(1, "limits error", 12);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

int	check_duplicates(char **num_char_set)
{
	int	i;
	int	j;

	i = 0;
	while (num_char_set[i])
	{
		j = i + 1;
		while (num_char_set[j])
		{
			if (ft_strcmp(num_char_set[i], num_char_set[j]) == 0)
			{
				write(1, "duplicates error", 16);
				return (FAILURE);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
