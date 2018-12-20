/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguarnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:31:43 by gguarnay          #+#    #+#             */
/*   Updated: 2018/12/14 00:07:01 by gguarnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char			*ft_strtrim(char const *s)
{
	int		beg;
	int		end;
	int		len;
	char	*ptr;
	char	*str;

	beg = 0;
	end = 0;
	if (!s)
		return (ft_strnew(0));
	len = ft_strlen(s);
	while (ft_is_space(s[beg]))
		beg++;
	str = (char *)s + (len - 1);
	while (ft_is_space(*str--))
		end++;
	if (end == len)
		return (ft_strnew(0));
	ptr = ft_strsub(s, beg, (len - (beg + end)));
	if (--beg == len)
		return (ft_strnew(0));
	return (ptr);
}
