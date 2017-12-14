/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:20:35 by jchung            #+#    #+#             */
/*   Updated: 2017/09/27 21:25:42 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*end_idx(char const *s, char c)
{
	while (*s && (char)*s != c)
		s++;
	return ((char *)s);
}

static int		word_count(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	char	*str;
	int		len;
	int		size;
	int		i;

	str = (char *)s;
	i = -1;
	if (str)
	{
		size = word_count(str, c);
		if (!(arr = (char **)ft_memalloc((sizeof(char *) * (size + 1)))))
			return ((char **)0);
		while (++i < size)
		{
			while (*str == c)
				str++;
			len = end_idx(str, c) - str;
			arr[i] = (char *)ft_memalloc((len * sizeof(char)) + 1);
			ft_strncpy(arr[i], str, len);
			str = end_idx(str, c);
		}
		return (arr);
	}
	return ((char **)0);
}
