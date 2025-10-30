/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 10:47:19 by fujisetaisu       #+#    #+#             */
/*   Updated: 2025/10/17 22:07:34 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*dest;
	size_t	i;

	dest = (char *)b;
	i = 0;
	while (i < len)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char arr[] = "aifhaihf";

// 	puts(arr);
// 	ft_memset(arr, 0, sizeof(arr));
// 	puts(arr);
// }
