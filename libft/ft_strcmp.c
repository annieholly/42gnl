/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:32:15 by aho               #+#    #+#             */
/*   Updated: 2017/10/15 00:46:49 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*u1;
	unsigned char	*u2;

	i = 0;
	u1 = (unsigned char*)s1;
	u2 = (unsigned char*)s2;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (u1[i] != u2[i])
			return (u1[i] - u2[i]);
		else
			i++;
	}
	return (u1[i] - u2[i]);
}
