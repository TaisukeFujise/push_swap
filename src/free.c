/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:10:13 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/02 08:19:17 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	free_num_str(char **num_str)
{
	int	i;

	i = 0;
	while (num_str[i])
	{
		free(num_str[i]);
		i++;
	}
	free(num_str);
}

void	free_stack(t_list *stack)
{
	
}

