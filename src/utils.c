/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 06:35:34 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/02 08:11:40 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	
	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}

int	*ft_atoi_map(char **num_char_set)
{
	int	set_size;
	int	*num_int_set;
	int	i;

	set_size = 0;
	while (num_char_set[set_size])
		set_size++;
	num_int_set = (int *)malloc(sizeof(int) * set_size);
	if (!num_int_set)
		return (NULL);
	while(num_char_set[i])
	{
		num_int_set[i] = ft_atoi(num_char_set[i]);
		i++;
	}
	return (num_int_set);
}