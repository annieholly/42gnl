/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 02:55:40 by jchung            #+#    #+#             */
/*   Updated: 2017/09/24 02:30:56 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*b1;
	char	*b2;
	char	*l1;

	if (!*little)
		return ((char *)big);
	b1 = (char *)big;
	while (*b1)
	{
		b2 = b1;
		l1 = (char *)little;
		while (*b2 && *l1 && *b2 == *l1)
		{
			b2++;
			l1++;
		}
		if (!*l1)
			return (b1);
		b1++;
	}
	return ((char *)0);
}
