/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguarnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 23:17:52 by gguarnay          #+#    #+#             */
/*   Updated: 2018/12/13 22:43:00 by gguarnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;
	char	*n;

	nlen = ft_strlen(needle);
	n = (char *)needle;
	if (!(*needle))
		return ((char *)haystack);
	while (len-- >= nlen && *haystack)
	{
		if ((ft_strncmp(haystack, needle, nlen) == 0 && (*haystack == *n)))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
