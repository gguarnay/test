/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguarnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 20:13:48 by gguarnay          #+#    #+#             */
/*   Updated: 2018/12/15 20:16:24 by gguarnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *begin_list, size_t nbr)
{
	size_t	i;
	t_list	*list;

	list = begin_list;
	i = 0;
	if (!(begin_list))
		return (NULL);
	while (list)
	{
		if (i == nbr)
			return (list);
		list = list->next;
		i++;
	}
	return (NULL);
}
