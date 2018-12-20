/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguarnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 19:57:50 by gguarnay          #+#    #+#             */
/*   Updated: 2018/12/15 19:59:54 by gguarnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *begin_list)
{
	size_t i;
	t_list *tmp;

	i = 0;
	if (!begin_list)
		return (0);
	tmp = begin_list;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (i + 1);
}
