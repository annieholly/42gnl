/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:57:23 by aho               #+#    #+#             */
/*   Updated: 2017/12/06 01:42:51 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int copyuntilnewline(char **saved, char **line)
{
//	printf("INSIDE COPY FUNCTION\n");
//	printf("BEGINNING - saved:%s...\n", *saved);
	char *savedstr;
	char *linestr; 
	char *temp;
	int len;
	int templen;
	int i;
	
	len = ft_strlen(*saved) + 1;
	savedstr = *saved;
	linestr = ft_memalloc(len);
	temp = ft_strchr(savedstr, '\n') + 1;
	templen = ft_strlen(temp) + 1;

	i = 0; 
	//handling newlines
	if (savedstr[i] == '\n')
	{
//		printf("i: %d\n", i);
		linestr[i] = savedstr[i];
		*line = linestr;
		temp = ft_strchr(savedstr, '\n') + 1;
		templen = ft_strlen(temp) + 1;
		ft_memmove(*saved, temp, templen);
//		printf("\nnewline detected - line:%s---\n", *line);
//		printf("\nnewline detected - saved:%s---\n", *saved);
		return (1);
	}
	while (savedstr[i] != '\n' && savedstr[i] != '\0')
	{
		linestr[i] = savedstr[i];
		i++;
	}
//	printf("savedstr[%i]: %c---\n", i, savedstr[i]);

	*line = linestr;
//	*saved = ft_strsub(savedstr, i, templen);
//	free(savedstr);
	temp = ft_strchr(savedstr, '\n');
	templen = ft_strlen(temp) + 1;

	ft_memmove(*saved, temp, templen);
//	*saved = ft_strchr(savedstr, '\n');
//	printf("\ninside copyuntil newline - line:%s---\n", *line);
//	printf("\ninside copyuntil newline - saved:%s---\n", *saved);
	return (1);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char *orig_s2;
	char *new;
	orig_s2 = s2;
	new = ft_strjoin(s1, s2);
	free(s1);
//	free(orig_s2);
	return (new);
}

int get_next_line(const int fd, char **line) 
{
//	printf("\n ------ CALLING GETNEXTLINE() ------- \n");
	int ret;
	char *buf;
	static char *saved;
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (saved == NULL && !(saved = ft_strnew(1)))
		return (-1);
	if (ft_strchr(saved, '\n') != NULL && copyuntilnewline(&saved, line))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		saved = ft_strjoin_free(saved, buf);
		if (ft_strchr(saved, '\n') != NULL && copyuntilnewline(&saved, line))
			return (1);
	}
//	free(buf);
//	free(saved);
//	printf("saved: %s \n", saved);
	return (0);
}
