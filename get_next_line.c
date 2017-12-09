/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:57:23 by aho               #+#    #+#             */
/*   Updated: 2017/12/08 22:54:14 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int ft_strsublen(char *str, int i, char c)
{
	while(str[i] != c)
		i++; 
	return (i); 
}

int findnl(char **saved, char **line, char *buf)
{
	int i;
	char *ptrsaved;
	char *newsaved;
	char *linestr;
	int newsavedlen;
	i = 0;
	if (!(newsaved = ft_strchr(*saved, '\n')))
		newsaved = buf;
	ptrsaved = *saved;
	*saved = ft_strjoin(ptrsaved, buf);
	ft_strdel(&ptrsaved);
	if (ft_strchr(*saved, '\n') == NULL) 
		return (0);
	ft_strdel(&buf);
	ptrsaved = *saved;
	if (ptrsaved[0] == '\n')
	{
		newsaved = ft_strchr(*saved, '\n') + 1;
		linestr = ft_strnew(1);
		linestr[i] = ptrsaved[0];
	}
	if (ft_strchr(ptrsaved, '\n') != NULL && ptrsaved[0] != '\n')
	{
		linestr = ft_strnew(ft_strsublen(ptrsaved, 0, '\n'));
		while (ptrsaved[i] != '\n')
		{
			linestr[i] = ptrsaved[i];
			i++;
		}
		linestr[i] = '\0';
		newsaved = ft_strchr(*saved, '\n'); 
	}
	if (newsaved == NULL)
		return (0);
//	newsavedlen = ft_strlen(newsaved);
	*saved = strdup(newsaved);
	*line = strdup(linestr);
	ft_strdel(&linestr);
	ft_strdel(&ptrsaved);
	return (1);
}


int get_next_line(const int fd, char **line) 
{
	int ret;
	char *buf;
	static char *saved;
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (saved == NULL && !(saved = ft_strnew(0)))
		return (-1);
	if (ft_strchr(saved, '\n') != NULL && findnl(&saved, line, buf))
	{
//		printf("\nreturn 1 - remaining line: %s--\n", *line);	
		return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ret < BUFF_SIZE) 
		{
			findnl(&saved, line, buf);
			free(saved);
			saved = NULL;
//B			printf("\nreturn 1 - last read line: %s--\n", *line);
			return (1);
		}
		if (findnl(&saved, line, buf) == 1)
		{
//			printf("\nreturn 1 - initial read line: %s--\n", *line);
			return (1);
		}
	}
	free(buf);
	return (0);
}
