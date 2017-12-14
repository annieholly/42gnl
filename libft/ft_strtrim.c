/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 22:10:45 by jchung            #+#    #+#             */
/*   Updated: 2017/09/21 01:41:58 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;

	if (s)
	{
		i = 0;
		j = ft_strlen(s);
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (i == j || !*s)
			str = ft_strnew(1);
		else
		{
			while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
				j--;
			str = ft_strnew(j - i);
		}
		if (str)
			ft_strncpy(str, &s[i], j - i);
		return (str);
	}
	return ((void *)0);
}
