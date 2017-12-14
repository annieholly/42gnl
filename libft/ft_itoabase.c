/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 01:36:12 by jchung            #+#    #+#             */
/*   Updated: 2017/11/29 11:08:23 by jchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	base_length(int n, int b)
{
	int len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > b - 1)
	{
		len++;
		n /= b;
	}
	return (++len);
}

char		*ft_itoabase(int n, int b)
{
	char	*arr;
	char	*nums;
	int		len;
	int		i;

	nums = (char *)malloc(sizeof(char) * 16);
	nums = "0123456789ABCDEF";
	if (b < 2 || b > 16)
		return ((void *)0);
	len = base_length(n, b);
	i = 0;
	arr = (char *)malloc(sizeof(char) * len);
	if (n < 0 && b == 10)
		arr[i++] = '-';
	while (n > b - 1)
	{
		arr[i++] = nums[ft_abs(n % b)];
		n /= b;
	}
	arr[i] = 0;
	free(nums);
	return (arr);
}
