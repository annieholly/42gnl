/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 02:36:18 by jchung            #+#    #+#             */
/*   Updated: 2017/09/29 17:29:56 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len2;

	if (!*little)
		return ((char *)big);
	len2 = ft_strlen(little);
	while (*big && len-- >= len2)
	{
		if (*big == *little && !(ft_strncmp(big, little, len2)))
			return ((char *)big);
		big++;
	}
	return ((char *)0);
}
