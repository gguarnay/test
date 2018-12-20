/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listpushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguarnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 19:42:52 by gguarnay          #+#    #+#             */
/*   Updated: 2018/12/15 20:30:24 by gguarnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **begin_list, t_list *new)
{
	t_list *current;

	if (!(*begin_list))
		*begin_list = new;
	else
	{
		current = *begin_list;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}
