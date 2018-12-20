/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguarnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 01:33:29 by gguarnay          #+#    #+#             */
/*   Updated: 2018/12/11 16:20:53 by gguarnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	char	*n;
	size_t	len;

	h = (char *)haystack;
	n = (char *)needle;
	len = ft_strlen(n);
	if (!len)
		return (h);
	while (*h)
	{
		if (!ft_strncmp(h, n, len))
			return (h);
		h++;
	}
	return ((char *)NULL);
}
