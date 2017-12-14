/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 06:21:51 by jchung            #+#    #+#             */
/*   Updated: 2017/09/26 20:12:59 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	char	*d;
	char	*s;
	size_t	dlen;
	size_t	sz;

	d = dst;
	s = (char *)src;
	sz = size;
	while (*d && sz--)
		d++;
	dlen = d - dst;
	if (size - dlen == 0)
		return (dlen + ft_strlen(src));
	while (*s && sz--)
		*d++ = *s++;
	while (*s)
		s++;
	*d = '\0';
	return (dlen + (s - src));
}
