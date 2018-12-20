/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguarnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:52:29 by gguarnay          #+#    #+#             */
/*   Updated: 2018/12/07 23:18:57 by gguarnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*cursor;

	if (!lst)
		return (NULL);
	cursor = f(lst);
	new_list = cursor;
	while (lst->next)
	{
		lst = lst->next;
		if (!(cursor->next = f(lst)))
		{
			free(cursor->next);
			return (NULL);
		}
		cursor = cursor->next;
	}
	return (new_list);
}
