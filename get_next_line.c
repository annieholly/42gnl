/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:57:23 by aho               #+#    #+#             */
/*   Updated: 2017/12/13 20:41:52 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int		nl_op(char **saved, char **line)
{
	char	*newsaved;
	char	*linestr;
	char	*nl;
	char	*afternl;

	nl = ft_strchr(*saved, '\n');
	afternl = nl + 1;
	newsaved = NULL;
//	if (saved == NULL)
//		return (0);
	if (nl)
	{
		linestr = ft_strsub(*saved, 0, nl - *saved);
		newsaved = ft_strdup(afternl);
	}
	else
	{
		linestr = ft_strdup(*saved);
		newsaved = ft_strnew(0);
	}
	*line = ft_strdup(linestr);
	ft_strdel(&linestr);
	ft_strdel(saved);
	*saved = ft_strdup(newsaved);
	ft_strdel(&newsaved);
	return (1); 
}



int		get_next_line(const int fd, char **l)
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
		s = ft_strjoin(s, buf);
		free(ptr_s);
	}
	ft_strdel(&buf);
//	ft_strdel(&ptr_s);
//	free(ptr_s);
	if (s[0] == '\0')
	{
		ft_strdel(&s);
		return (0);
	}
	if (nl_op(&s, l) == 1)
		return (1);
	return (0);
}
