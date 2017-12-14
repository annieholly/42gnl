/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:57:23 by aho               #+#    #+#             */
/*   Updated: 2017/12/13 19:19:43 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int		nl_op(char **saved, char **line)
{
//	printf(">> nl_op call <<\n");
	char	*newsaved;
	char	*linestr;
	char	*nl;
	char	*afternl;

	nl = ft_strchr(*saved, '\n');
	afternl = nl + 1;
	newsaved = NULL;
	if (*saved == NULL)
	  return (0);
	if (nl) 
	{
		linestr = ft_strsub(*saved, 0, nl - *saved);
		newsaved = ft_strdup(afternl);
	}
	else 
		linestr = ft_strdup(*saved);
	*line = ft_strdup(linestr);
	ft_strdel(&linestr);
	*saved = newsaved;
	//printf("\n*line before return:%s--\n", *line);
	//printf("*saved before return:%s--\n", *saved);
	return (1); 
}

char *ft_strjoin_free(char *s1, char *s2) 
{
	//char *orig_s1; 
	char *newstr; 
	//orig_s1 = s1; 
//	newstr = ft_strjoin(orig_s1, s2);
//	ft_strdel(&orig_s1);
	newstr = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (newstr);
}

int		get_next_line(const int fd, char **l)
{
	int				ret;
	char			*buf;
	static char		*s;
//	char			*ptr_s;
//	printf("--GNL CALLED-- \n");
	if (!(buf = ft_strnew(BUFF_SIZE)) || (!l) || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (s == NULL && !(s = ft_strnew(0)))
		return (-1);
	if (ft_strchr(s, '\n') != NULL && ft_strlen(s) != 1 && nl_op(&s, l) == 1)
	  {
	    //printf("return 1 - remaining saved \n");
		return (1);
	  }

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
//		ptr_s = s;
		s = ft_strjoin_free(s, buf);
//		free(ptr_s);
//		if (ft_strchr(s, '\n') != NULL)
//			break ;
	}
	ft_strdel(&buf);
	if (s[0] == '\0')
	{
	  //free(s);
	  //printf("saved is null, return 0 \n");
	  return (0);
	}
	if (nl_op(&s, l) == 1)
	{
	  //printf("initial findnl return 1 \n");
	  return (1);
	}
    //printf("last return = 0 \n");
	return (0);
}
