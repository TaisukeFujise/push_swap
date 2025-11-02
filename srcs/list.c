/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 08:55:06 by tafujise          #+#    #+#             */
/*   Updated: 2025/11/02 22:20:39 by tafujise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_lstnew(int	content)
{
	t_list	*new_node;

	new_node = (t_list*)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node -> content = content;
	new_node -> next = NULL;
	new_node -> prev = NULL;
	return new_node;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new -> next = *lst;
	(*lst) -> prev = new;
	*lst = new;
	return ;
}

int	ft_lstsize(t_list *lst)
{
	size_t	size;

	if (lst == NULL)
		return (0);
	size = 0;
	while (lst -> next)
	{
		size++;
		lst = lst -> next;
	}
	size++;
	return (size);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current -> next)
		current = current -> next;
	current -> next = new;
	new -> prev = current;
	return ;
}
