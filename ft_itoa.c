/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ioa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguarnay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:18:07 by gguarnay          #+#    #+#             */
/*   Updated: 2018/12/13 21:35:20 by gguarnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_digit(int n)
{
	int				i;
	unsigned int	nb;
	int				sign;

	nb = n;
	sign = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nb = -n;
		sign = 1;
	}
	i = 0;
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i + sign);
}

static void		ft_str_rev(char **s)
{
	size_t	len;
	size_t	i;
	char	temp;

	len = ft_strlen(*s);
	i = 0;
	if (len < 2)
		return ;
	while (i <= (len - 1) / 2)
	{
		temp = (*s)[i];
		(*s)[i] = (*s)[len - 1 - i];
		(*s)[len - 1 - i] = temp;
		i++;
	}
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*r;
	size_t	i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = ft_nb_digit(n);
	r = ft_strnew(len);
	i = 0;
	if (n < 0)
		return (ft_strjoin("-", ft_itoa(-n)));
	while (i < len)
	{
		r[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	r[len] = '\0';
	ft_str_rev(&r);
	return (r);
}
