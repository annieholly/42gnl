/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 14:41:53 by jchung            #+#    #+#             */
/*   Updated: 2017/09/29 15:08:58 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*itr;
	t_list	*tmp;

	if (!lst || !f)
		return ((void *)0);
	head = (*f)(lst);
	itr = head;
	while (lst->next)
	{
		lst = lst->next;
		tmp = (*f)(lst);
		if (tmp)
			itr->next = tmp;
		else
			return ((void *)0);
		itr = itr->next;
	}
	return (head);
}
