/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 07:47:26 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/02 07:47:32 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	is_in_int_min(char *num_str)
{
	char *int_min_str;

	int_min_str = ft_itoa(INT_MIN);
	if (ft_strlen(num_str) > ft_strlen(int_min_str))
		return (FAILURE);
	else if (ft_strlen(num_str) < ft_strlen(int_min_str))
		return (SUCCESS);
	if (ft_strcmp(num_str, int_min_str) > 0)
		return (FAILURE);
	else if (ft_strcmp(num_str, int_min_str) <= 0)
		return (SUCCESS);
}

int	is_in_int_min(char *num_str)
{
	char *int_max_str;

	int_max_str = ft_itoa(INT_MAX);
	if (ft_strlen(num_str) > ft_strlen(int_max_str))
		return (FAILURE);
	else if (ft_strlen(num_str) < ft_strlen(int_max_str))
		return (SUCCESS);
	if (ft_strcmp(num_str, int_max_str) > 0)
		return (FAILURE);
	else if (ft_strcmp(num_str, int_max_str) <= 0)
		return (SUCCESS);
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