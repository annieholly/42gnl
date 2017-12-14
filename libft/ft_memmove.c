/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 22:23:53 by jchung            #+#    #+#             */
/*   Updated: 2017/09/22 00:04:22 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *restrict dst, const void *restrict src, size_t n)
{
	char	*dptr;
	char	*sptr;

	dptr = (char *)dst;
	sptr = (char *)src;
	while (n-- > 0)
		if (sptr < dptr)
			*(dptr + n) = *(sptr + n);
		else
			*dptr++ = *sptr++;
	return (dst);
}
