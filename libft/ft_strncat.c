/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 05:20:55 by jchung            #+#    #+#             */
/*   Updated: 2017/09/28 12:20:12 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*str;

	str = s1;
	while (*str)
		str++;
	while (n-- > 0 && *s2)
		*str++ = *s2++;
	*str = 0;
	return (s1);
}
