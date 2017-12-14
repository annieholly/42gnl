/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 20:47:05 by jchung            #+#    #+#             */
/*   Updated: 2017/09/26 09:33:18 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	if (!*s)
		return (0);
	ptr = (void *)0;
	while (*s)
	{
		if (*s == c)
			ptr = (char *)s;
		s++;
	}
	if (!c)
		return ((char *)s);
	return ((char *)ptr);
}
