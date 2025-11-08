/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 07:45:06 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/09 07:49:15 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_min(int value1, int value2)
{
	if (value1 <= value2)
		return (value1);
	return (value2);
}

int	ft_max(int value1, int value2)
{
	if (value1 >= value2)
		return (value1);
	return (value2);
}
