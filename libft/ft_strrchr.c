/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:40:26 by fujisetaisu       #+#    #+#             */
/*   Updated: 2025/10/17 22:08:29 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;

	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
		{
			temp = (char *)s;
			s++;
			while (*s && ((unsigned char)*s != (unsigned char)c))
				s++;
			if (*s == '\0')
			{
				if ((unsigned char)c == '\0')
					return ((char *)s);
				return (temp);
			}
			continue ;
		}
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char str[] = "abcdbaba";
// 	char c = 'b';
// 	puts(ft_strrchr(str, c));
// }
