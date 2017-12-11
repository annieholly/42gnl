/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:57:23 by aho               #+#    #+#             */
/*   Updated: 2017/12/10 23:51:33 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int ft_strsublen(char *str, int i, char c)
{
	int count;
	count = 0;
	while (str[i] != c)
	{
		count++;
		i++;
	}
	return (count); 
}

int findnl(char **saved, char **line)
{
//	printf("inside findnl saved:%s--\n", *saved);
	int i;
	char *ptrsaved;
	
char *newsaved;
	char *linestr;
	i = 0;
	if (saved[0] == '\0')
		return (0);

//	if (ft_strchr(*saved, '\n') == NULL)
//		return (0);
	ptrsaved = *saved;
//	linestr = *saved;
//	printf("ptrsaved:%s--\n", ptrsaved);
	if (ptrsaved[0] == '\n')
	{
//		printf("ptrsaved[0] newline \n");
		linestr = ft_strnew(1);
		linestr[i] = '\0';
	}
	if (ft_strchr(ptrsaved, '\n') != NULL && ptrsaved[0] != '\n')
	{
//		printf("processing nl\n");
//		printf("ptrsaved:%s--\n", ptrsaved);
//		if (linestr != NULL) 
//			free(linestr);

		linestr = ft_strnew(ft_strsublen(ptrsaved, 0, '\n'));
		while (ptrsaved[i] != '\n')
		{
			linestr[i] = ptrsaved[i];
			i++;
		}
		linestr[i] = '\0';
	}
	if (linestr == NULL) 
		linestr = *saved;


	*line = strdup(linestr);
//	printf("return - inside findnl line:%s---\n", *line);
	ft_strdel(&linestr);
//	ft_strdel(&ptrsaved);
	if (ft_strchr(ptrsaved, '\n') != NULL)
	{	
		if (ptrsaved[0] == '\n' && ft_strlen(ptrsaved) == 1)
			newsaved = ft_strchr(ptrsaved, '\n');
		else 
			newsaved = ft_strchr(ptrsaved, '\n') + 1;
//		printf("newsaved:%s--\n", newsaved);


		*saved = strdup(newsaved);

		ft_strdel(&ptrsaved);
//		printf("return - inside findnl saved:%s--\n", *saved);
		return (1);
	}
//	printf("return - inside findnl saved:%s--\n", *saved);
//	ft_strdel(&ptrsaved);
	return (1);
}

int get_next_line(const int fd, char **line) 
{
	printf("\n----GETNEXTLINE CALLED-----\n");
	int ret;
	char *buf;
	static char *saved;
	char *ptr_s;
	if (!(buf = ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	printf("saved:%s--\n", saved);
/*
	if (saved != NULL && saved[0] == '\0')
	{
		ft_strdel(&buf);
		return (0);
	}
*/

//	if (saved != NULL && findnl(&saved, line))
//	{
//		return (1);
//	}
	if (saved == NULL && !(saved = ft_strnew(0)))
		return (-1);
//	if (ft_strchr(saved, '\n') != NULL && ft_strlen(saved) != 1)	


//	if (ft_strchr(saved, '\n') != NULL && findnl(&saved, line) && ft_strlen(saved) != 1)
//	if (saved != NULL && findnl(&saved, line, buf))
	if (ft_strchr(saved, '\n') != NULL && ft_strlen(saved) != 1)
	{
		findnl(&saved, line);
//		printf("bloop\n");
//		printf("\nreturn 1 - remaining line: %s--\n", *line);
//		ft_strdel(&buf);
		return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
//		printf("ret is %d\n", ret);
		buf[ret] = '\0';
		ptr_s = saved;
//		ptr_b = buf;
//		saved = ft_strjoin(ptr_s, ptr_b);
//		printf("buf:%s--\n", buf);
//		printf("ptr_s:%s--\n", ptr_s);
		saved = ft_strjoin(ptr_s, buf);
//		printf("FT_STRJOIN: %i --- saved:%s--\n\n", i, saved);
		ft_strdel(&ptr_s);
		if (ft_strchr(saved, '\n') != NULL)
		{
//			ft_strdel(&buf);
			break;
		}
	}









//	ft_strdel(&buf);
	if (findnl(&saved, line) == 1)
	{
//		printf("\nreturn 1 - initial read line:%s--\n", *line);
		ft_strdel(&buf);


		if (saved != NULL && saved[0] == '\0')
		{
			ft_strdel(&buf);
			return (0);
		}




		return (1);
	}
	ft_strdel(&buf);
//	ft_strdel(&saved);
	close(fd);
//	printf("return 0\n");
	return (0);
}
