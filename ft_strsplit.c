/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguarnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:14:44 by gguarnay          #+#    #+#             */
/*   Updated: 2018/12/13 23:56:22 by gguarnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wc(char const *s, char c)
{
	size_t	flag;
	size_t	wc;

	flag = 0;
	wc = 0;
	while (*s)
	{
		if (*s == c && flag == 1)
			flag = 0;
		else if (*s != c && flag == 0)
		{
			wc++;
			flag = 1;
		}
		s++;
	}
	return (wc);
}

static size_t	*ft_wlen_arr(char const *s, char c, size_t wc)
{
	size_t	*wlen;
	size_t	i;

	if (!(wlen = (size_t *)malloc(sizeof(size_t) * wc)))
		return (NULL);
	i = 0;
	while (i < wc)
	{
		wlen[i] = 0;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			wlen[i]++;
			s++;
		}
		i++;
	}
	return (wlen);
}

static size_t	ft_next_start(char const *s, size_t start, size_t len, char c)
{
	size_t i;

	i = start + len;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	wc;
	char	**tab;
	size_t	*wlen;
	size_t	i;
	size_t	start;

	if (!s || !c)
		return (NULL);
	while (*s == c)
		s++;
	wc = ft_wc(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (wc + 1))))
		return (NULL);
	wlen = ft_wlen_arr(s, c, wc);
	i = 0;
	start = 0;
	while (i < wc)
	{
		tab[i] = ft_strsub(s, start, wlen[i]);
		start = ft_next_start(s, start, wlen[i], c);
		i++;
	}
	tab[i] = 0;
	free(wlen);
	return (tab);
}
