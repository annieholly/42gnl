/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:57:29 by jchung            #+#    #+#             */
/*   Updated: 2017/10/01 17:36:06 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;

	if (!s || start > ft_strlen(s))
		return ((void *)0);
	s2 = ft_strnew(len);
	return (s2 ? ft_strncpy(s2, &s[start], len) : (void *)0);
}
