/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:23:19 by aascedu           #+#    #+#             */
/*   Updated: 2022/11/24 09:08:56 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstnew2(void *content, void (*del)(void *))
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
	{
		del(content);
		return (NULL);
	}
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		new = ft_lstnew2(f(lst->content), del);
		if (!new)
			ft_lstclear(&first, del);
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
