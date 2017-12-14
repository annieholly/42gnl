/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:57:23 by aho               #+#    #+#             */
/*   Updated: 2017/12/13 23:05:26 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int			nl_op(char **saved, char **line)
{
	char	*newsaved;
	char	*nl;

	nl = ft_strchr(*saved, '\n');
	if (nl)
	{
		*line = ft_strsub(*saved, 0, nl - *saved);
		newsaved = ft_strdup(nl + 1);
	}
	else
	{
		*line = ft_strdup(*saved);
		newsaved = ft_strnew(0);
	}
	ft_strdel(saved);
	*saved = ft_strdup(newsaved);
	ft_strdel(&newsaved);
	return (1);
}

int			get_next_line(const int fd, char **l)
{
	int				ret;
	char			*buf;
	static char		*s;
	char			*ptr_s;

	if (!(buf = ft_strnew(BUFF_SIZE)) || (!l) || fd < 0 ||
		read(fd, buf, 0) < 0 || (s == NULL && !(s = ft_strnew(0))))
		return (-1);
	if (ft_strchr(s, '\n') != NULL && ft_strlen(s) != 1 && nl_op(&s, l) == 1)
	{
		ft_strdel(&buf);
		return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ptr_s = s;
		s = ft_strjoin(ptr_s, buf);
		free(ptr_s);
		if (ft_strchr(s, '\n') != NULL)
		  break ;
	}
	ft_strdel(&buf);
	if (s[0] != '\0' && nl_op(&s, l) == 1)
		return (1);
	ft_strdel(&s);
	return (0);
}
