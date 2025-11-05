/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 06:35:34 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/05 23:05:52 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**ft_str_arr_dup(char **str_arr)
{
	int		i;
	char	**dup_arr;

	if (str_arr == NULL)
		return (NULL);
	dup_arr = (char **)malloc(sizeof(char *) * (count_set_size(str_arr) + 1));
	if (!dup_arr)
		return (NULL);
	i = 0;
	while (str_arr[i])
	{
		dup_arr[i] = ft_strdup(str_arr[i]);
		if (dup_arr[i] == NULL)
		{
			while (i > 0)
			{
				i--;
				free((dup_arr)[i]);
			}
			return (free(dup_arr), NULL);
		}
		i++;
	}
	dup_arr[i] = NULL;
	return (dup_arr);
}

int	count_set_size(char **num_char_set)
{
	int	count;

	count = 0;
	if (num_char_set == NULL)
		return (0);
	while (num_char_set[count])
		count++;
	return (count);
}

int	*ft_atoi_map(char **num_char_set)
{
	int	num_set_size;
	int	*num_int_set;
	int	i;

	i = 0;
	num_set_size = count_set_size(num_char_set);
	num_int_set = (int *)malloc(sizeof(int) * (num_set_size));
	if (!num_int_set)
		return (NULL);
	while (i < num_set_size)
	{
		num_int_set[i] = ft_atoi(num_char_set[i]);
		i++;
	}
	return (num_int_set);
}

int	is_stack_sorted(t_list *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (SUCCESS);
	while (stack->next != NULL)
	{
		if ((stack->content) > (stack->next->content))
			return (FAILURE);
		stack = stack->next;
	}
	return (SUCCESS);
}

int	is_stack_empty(t_list *stack)
{
	if (stack == NULL)
		return (SUCCESS);
	return (FAILURE);
}
