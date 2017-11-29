/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:57:23 by aho               #+#    #+#             */
/*   Updated: 2017/11/29 00:41:58 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_SIZE 42

void copyuntilnewline(char **saved, char **line)
{
//	printf("INSIDE COPY FUNCTION\n");
	char *savedstr;
	char *linestr; 
	int len;
	int i;
	len = ft_strlen(*saved) + 1;
	savedstr = *saved;
	linestr = ft_memalloc(len);
	i = 0; 
//	printf("savedstr: %s \n", savedstr);
//	printf("savedstr[%i]: %c \n", i, savedstr[i]);
	while (savedstr[i] != '\n' && savedstr[i] != '\0')
	{
		linestr[i] = savedstr[i];
		i++;
	}
	*line = linestr;

	*saved = ft_strchr(savedstr, '\n') + 1;
//	printf("*saved: %s\n", *saved);
}

int containsnewline(char *saved)
{
	if (ft_strchr(saved, '\n') != NULL)
		return (1); 
	return (0);
}

int get_next_line(const int fd, char **line) 
{
	printf("\n ------ CALLING GETNEXTLINE() ------- \n");
	int ret;
	char buf[BUFF_SIZE + 1];
	static char *saved;

	if (saved == NULL)
	{	
		saved = ft_strnew(1);
		saved[0] = '\0'; 
	}
//	printf("printing line: %s \n", *line);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ft_putstr(">>>>> buf: ");
		ft_putstr(buf);
		ft_putchar('\n');
		//keep saving if there's no new line
		//break if there's a new line
		//SAVE TO SAVED
		saved = ft_strjoin(saved, buf);
		ft_putstr(">>>>> saved: ");
		ft_putstr(saved);
		ft_putstr("\n\n");
		if (ft_strchr(saved, '\n') != NULL)
			break ;
	}
	//IF HAS NEW LINE, copy until the new line and save the line read to **line
	// new saved buffer
	//return 1
	if (containsnewline(saved) == 1)
	{
		copyuntilnewline(&saved, line);
//		printf("\nline: %s\n", *line);
//		printf("\nsaved: %s\n", saved);
		return (1);
	}
	//IF SAVED HAS NOTHING, RETURN O - READING COMPLETE
	if (containsnewline(saved) == 0)
	{
		return (0);
	}
	return (0);
}

int main(int argc, char **argv)
{
    int fd;
    char *line;
    fd = open(argv[1], O_RDONLY);
    if (argc != 2)
        printf("Invalid \n");
    if (argc == 2)
    {
        if (fd == -1)
        {
            printf("open () failed \n");
            return (1);
        }
        while (get_next_line(fd, &line) == 1)
		{
			printf("\n>>  gnl successful!\n");
			printf("print line: %s\n", line);
		}
    }
}
