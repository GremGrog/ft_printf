/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 22:43:34 by qmebble           #+#    #+#             */
/*   Updated: 2018/12/04 23:41:41 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	all_free(t_list **lst)
{
	t_list *space;

	while (lst)
	{
		space = (*lst)->next;
		free(lst);
		*lst = space;
	}
	(*lst) = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlist;
	t_list	*slist;

	if (!lst || !f)
		return (NULL);
	nlist = ft_lstnew(NULL, 0);
	nlist = f(lst);
	if (nlist == NULL)
		return (NULL);
	slist = nlist;
	while (lst->next)
	{
		lst = lst->next;
		nlist->next = f(lst);
		if (nlist->next == NULL)
		{
			all_free(&slist);
			return (NULL);
		}
		nlist = nlist->next;
	}
	return (slist);
}
