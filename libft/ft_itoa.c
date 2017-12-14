/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 02:46:01 by jchung            #+#    #+#             */
/*   Updated: 2017/09/29 16:30:50 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(int n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (++len);
}

char		*ft_itoa(int n)
{
	char			*buf;
	int				i;
	unsigned int	x;

	buf = ft_strnew(length(n));
	if (!buf)
		return ((char *)0);
	i = 0;
	x = n;
	x = n < 0 ? -x : x;
	buf[i] = '0';
	while (x != 0)
	{
		buf[i] = x % 10 + '0';
		i++;
		x /= 10;
	}
	if (n < 0)
		buf[i++] = '-';
	ft_strrev(buf);
	return (buf);
}
