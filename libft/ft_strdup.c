/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:23:25 by aho               #+#    #+#             */
/*   Updated: 2017/12/14 15:09:30 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dupe;

	i = 0;
	if (!s1) 
		return (0);
	if (!(dupe = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	while (s1[i] != '\0')
	{
		dupe[i] = s1[i];
		i++;
	}
	dupe[i] = '\0';
	return (dupe);
}
