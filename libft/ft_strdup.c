/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 18:03:29 by jchung            #+#    #+#             */
/*   Updated: 2017/09/21 22:05:39 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char *s2;

	if (!(*s1))
		return (ft_strnew(1));
	s2 = ft_strnew(ft_strlen(s1));
	return (s2 ? ft_strcpy(s2, s1) : (void *)0);
}
