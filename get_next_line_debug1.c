/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:57:23 by aho               #+#    #+#             */
/*   Updated: 2017/12/08 15:01:25 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
/*

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

//	printf("\n\n------ENTERING FINDNL--------\n");
	i = 0;

//	printf("before strchr \n");
	if (!(newsaved = ft_strchr(*saved, '\n')))
		newsaved = buf;
//	printf("newsaved:%s--\n", newsaved);
//	printf("before strjoin \n")
	ptrsaved = *saved;
	//join together what's saved with buf;
	*saved = ft_strjoin(ptrsaved, buf);
	ft_strdel(&ptrsaved);
//	ft_strdel(&buf);

	if (ft_strchr(*saved, '\n') == NULL) 
		return (0);
//	free(ptrsaved);
//	free(buf);
//	ft_strdel(&ptrsaved);
	ft_strdel(&buf);
	//point to newly joined saved
	ptrsaved = *saved;
//	printf("ptrsaved:%s--\n", ptrsaved);
	if (ptrsaved[0] == '\n')
	{
		newsaved = ft_strchr(*saved, '\n') + 1;
//		printf("newsaved(nl only):%s--\n", newsaved);
		linestr = ft_strnew(1);
		linestr[i] = ptrsaved[0];
//		printf("line(nl only):%s--\n", *line);
	}
	if (ft_strchr(ptrsaved, '\n') != NULL && ptrsaved[0] != '\n')
	{
		linestr = ft_strnew(ft_strsublen(ptrsaved, 0, '\n'));
//		printf("ft_strsublen: %d\n", ft_strsublen(ptrsaved, 0, '\n'));
//		printf("after linestr memalloc \n");
		while (ptrsaved[i] != '\n' && ptrsaved[i] != '\0')
		{
//			printf("i: %i, %c <- %c \n", i, linestr[i], ptrsaved[i]);
			linestr[i] = ptrsaved[i];
			i++;
		}
		linestr[i] = '\0';
//		printf("linestr:%s\n", linestr);

		//free(newsaved);
		newsaved = ft_strchr(*saved, '\n'); 
//		newsavedlen = ft_strlen(newsaved);
//		printf("newsavedlen when nl found:%d--\n", newsavedlen);
//		printf("newsavedstr when nl found:%s--\n", newsaved);
	}
	if (newsaved == NULL)
	{
		printf("newsaved is null\n");
		return (0);
	}
	//get the length of the new saved str

	newsavedlen = ft_strlen(newsaved);
//	printf("newsavedlen for *saved:%d\n", newsavedlen);
	//malloc for the new saved str
//	*saved = ft_memalloc(newsavedlen) + 1;
	*saved = strdup(newsaved);
//	printf("*saved:%s--\n", *saved);
//	ft_memmove(*saved, newsaved, newsavedlen);
//	printf("*saved after memmove:%s--\n", *saved);

//	printf("linestr:%s\n", linestr);
	*line = strdup(linestr);
//	free(linestr);
//	free(ptrsaved);
	ft_strdel(&linestr);
	ft_strdel(&ptrsaved);
//	printf("line:%s--\n", *line);
	return (1);

}


int get_next_line(const int fd, char **line) 
{
//	printf("\n ------ CALLING GETNEXTLINE() ------- \n");
	int ret;
	char *buf;
	static char *saved;
//	int savedlen;

	//MALLOC some space for buf
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);

	//MALLOC some space for saved
	if (saved == NULL && !(saved = ft_strnew(0)))
		return (-1);

	//process what's in saved if there are any additional newlines
	if (ft_strchr(saved, '\n') != NULL && findnl(&saved, line, buf))
			return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
//		printf("\n--------- A FRESH NEW READ HAS OCCURED! ---------- \n");
		buf[ret] = '\0';
		//this function should store the line and save remainder to saved
		//if it doesn't return 1, program should keep reading from fd
		if (findnl(&saved, line, buf) == 1)
			return (1);
//		printf("outside of return \n");
		//savedlen = ft_strlen(saved);
		//saved = ft_memalloc(savedlen + BUFF_SIZE + 1);	
		//saved = ft_strcat(saved, buf);
//		printf("\n->>> before strjoin - saved:%s--\n", saved);
//		printf("-> before strjoinfree - buf:%s--\n", buf);
//		printf("\n->>> after strjoin - saved:%s--\n", saved);
//		printf("-> after strjoinfree - buf:%s--\n", buf);
	}
	free(buf);
//	free(saved);
//	printf("saved: %s \n", saved);
	return (0);
}
*/
