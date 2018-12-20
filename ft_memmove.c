/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguarnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:48:28 by gguarnay          #+#    #+#             */
/*   Updated: 2018/12/11 20:01:54 by gguarnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	if (p2 < p1)
	{
		p1 += len - 1;
		p2 += len - 1;
		while (len--)
			*p1-- = *p2--;
	}
	else
	{
		while (len--)
		{
			*p1++ = *p2++;
		}
	}
	return (dst);
}
