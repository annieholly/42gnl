/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 05:19:22 by jchung            #+#    #+#             */
/*   Updated: 2017/11/29 11:07:30 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*tmp;

	if (!size)
	{
		free(ptr);
		return ((void *)0);
	}
	if (!(tmp = ft_memalloc(size)))
		return ((void *)0);
	if (!ptr)
		return (tmp);
	ft_memcpy(tmp, ptr, size);
	free(ptr);
	return (tmp);
}
