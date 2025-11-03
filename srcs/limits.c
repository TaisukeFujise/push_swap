/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 07:47:26 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/04 07:28:33 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_in_int_min(char *num_str)
{
	char	*int_min_str;

	int_min_str = ft_itoa(INT_MIN);
	if (!int_min_str)
		return (FAILURE);
	if (ft_strlen(num_str) > ft_strlen(int_min_str))
		return (free(int_min_str), FAILURE);
	else if (ft_strlen(num_str) < ft_strlen(int_min_str))
		return (free(int_min_str), SUCCESS);
	else if (ft_strcmp(num_str, int_min_str) > 0)
		return (free(int_min_str), FAILURE);
	else
		return (free(int_min_str), SUCCESS);
}

int	is_in_int_max(char *num_str)
{
	char	*int_max_str;

	int_max_str = ft_itoa(INT_MAX);
	if (!int_max_str)
		return (FAILURE);
	if (ft_strlen(num_str) > ft_strlen(int_max_str))
		return (free(int_max_str), FAILURE);
	else if (ft_strlen(num_str) < ft_strlen(int_max_str))
		return (free(int_max_str), SUCCESS);
	else if (ft_strcmp(num_str, int_max_str) > 0)
		return (free(int_max_str), FAILURE);
	else
		return (free(int_max_str), SUCCESS);
}

int	is_in_int_limits(char *num_str)
{
	if (num_str[0] == '-')
	{
		if (!is_in_int_min(num_str))
			return (FAILURE);
		return (SUCCESS);
	}
	else
	{
		if (!is_in_int_max(num_str))
			return (FAILURE);
		return (SUCCESS);
	}
}
