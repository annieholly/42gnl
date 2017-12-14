/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 18:55:56 by jchung            #+#    #+#             */
/*   Updated: 2017/09/28 11:52:11 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*cpy;

	cpy = dst;
	while (len > 0 && *src)
	{
		*cpy++ = *src++;
		len--;
	}
	while (len-- > 0)
		*cpy++ = 0;
	return (dst);
}
