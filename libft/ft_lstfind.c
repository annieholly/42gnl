/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:54:21 by jchung            #+#    #+#             */
/*   Updated: 2017/11/29 16:07:13 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list **alst, int data)
{
	t_list	*itr;

	itr = *alst;
	while (itr)
	{
		if (itr->content_size == (size_t)data)
			return (itr);
		itr = itr->next;
	}
	return ((t_list *)0);
}
