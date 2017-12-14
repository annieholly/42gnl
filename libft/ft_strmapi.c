/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:26:53 by jchung            #+#    #+#             */
/*   Updated: 2017/09/19 16:36:33 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s2;
	int		i;
	int		len;

	if (s)
	{
		i = 0;
		len = ft_strlen(s);
		s2 = ft_strnew(len);
		while (i < len && s2)
		{
			s2[i] = (*f)(i, s[i]);
			i++;
		}
		return (s2);
	}
	return ((void *)0);
}
