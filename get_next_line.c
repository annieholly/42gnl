/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:57:23 by aho               #+#    #+#             */
/*   Updated: 2017/12/12 00:29:50 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int		ft_strsublen(char *str, int i, char c)
{
	int		count;

	count = 0;
	while (str[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

int		nl_op(char **saved, char **line)
{
//	printf(">> nl_op call <<\n");
	int		i;
	char	*ptrsaved;
	char	*newsaved;
	char	*linestr;
	int 	linestrlen;

//	printf("\n*line begin nl_op:%s--\n", *line);
//	printf("*saved being nl_op:%s--\n", *saved);
	i = 0;
//	ptrsaved = ft_strdup(*saved);
      	ptrsaved = *saved;

	//if ptrsaved is NULL, return 1
	if (ptrsaved == NULL)
	  return (0);
	
	//if newline is in *saved
	// a. malloc space on linestr
	// b. malloc space on newsaved
	

	//else no newline found
	// a. malloc space on linestr 
	// b. malloc space on newsaved
	if (ft_strchr(*saved, '\n') != NULL) 
	{
//		printf("bloop\n");
		linestrlen = ft_strsublen(*saved, 0, '\n');
		linestr = ft_strsub(ptrsaved, 0, linestrlen);
		newsaved = ft_strdup(ft_strchr(ptrsaved, '\n') + 1);
//		ft_strdel(&ptrsaved);

	}
	else 
	{
		//printf("%s\n", ptrsaved);
		linestr = ft_strdup(ptrsaved);
//		ft_strdel(&ptrsaved);
		newsaved = ft_strnew(0);
	}
	*line = ft_strdup(linestr);
	ft_strdel(&linestr);

	*saved = ft_strdup(newsaved); 
	ft_strdel(&newsaved);
	//ft_strdel(&ptrsaved);

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

//	testfunction();

	if (!(buf = ft_strnew(BUFF_SIZE)) || fd < 0 || (!l) || read(fd, buf, 0) < 0)
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
		//printf("s after strjoin:%s--\n",s);
//		free(ptr_s);
		if (ft_strchr(s, '\n') != NULL)
			break ;
	}
	ft_strdel(&buf);
//	if (ret < 0)
//		return (-1);

//	if (s == NULL) 
//		return (0);

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

       	/*if (s[0] == '\0')
	{
	  //free(s);
	  //printf("saved is null, return 0 \n");
	  return (0);
	  }*/
	

       	//printf("last return = 0 \n");
	return (0);
}
