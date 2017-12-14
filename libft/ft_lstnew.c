/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 12:49:33 by jchung            #+#    #+#             */
/*   Updated: 2017/11/23 03:26:45 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return ((void *)0);
	if (!content)
	{
		node->content = (void *)0;
		node->content_size = 0;
	}
	else
	{
		node->content_size = content_size;
		if (!(node->content = (void *)malloc(sizeof(content))))
			return ((void *)0);
		ft_memcpy(node->content, content, node->content_size);
	}
	node->next = (void *)0;
	return (node);
}
