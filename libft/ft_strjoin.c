/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 01:08:01 by aho               #+#    #+#             */
/*   Updated: 2017/10/15 19:57:32 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*concat_str;
	char		*str1;
	char		*str2;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	str1 = (char*)s1;
	str2 = (char*)s2;
	concat_str = ft_memalloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!s1 || !s2 || concat_str == NULL)
		return (NULL);
	while (str1[i] != '\0')
	{
		concat_str[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
		concat_str[i++] = str2[j++];
	concat_str[i] = '\0';
	return (concat_str);
}
