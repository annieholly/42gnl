/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 01:08:01 by aho               #+#    #+#             */
/*   Updated: 2017/12/14 15:27:41 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*concat_str;

	if (!s1 || !s2)
		return (0);
	concat_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (concat_str)
	{
		ft_strcpy(concat_str, s1);
		ft_strcpy(&concat_str[ft_strlen(s1)], s2);
		return (concat_str);
	}
	return (0);
}
