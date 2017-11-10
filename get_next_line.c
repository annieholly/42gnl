/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:57:23 by aho               #+#    #+#             */
/*   Updated: 2017/11/09 23:06:53 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_SIZE 42


int processnewline(char *saved, char **line)
{
	if (ft_strchr(saved, '\n') != NULL)
	{
		line = copyuntilnewline(saved);
		saved = ft_strchr(saved, '\n');
		return (1); 
	}










}


int get_next_line(const int fd, char **line) 
{
	int ret;
	char buf[BUFF_SIZE + 1];
	static char *saved; 

	if (saved == NULL)
	{	
		saved = ft_strnew(1);
		saved[0] = '\0'; 
	}

//	printf("file successfully opened\n inside getnextline() \n");
	printf("printing line: %s \n", *line);

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0) //keep reading
	{
		//PRINT BUF
		buf[ret] = '\0';
		ft_putstr("buf: ");
		ft_putstr(buf);
		ft_putchar('\n');

		//keep saving if there's no new line
		//break if there's a new line

		//SAVE TO SAVED
		saved = ft_strjoin(saved, buf);
		ft_putstr("saved: ");
		ft_putstr(saved);
		ft_putchar('\n');
		if (ft_strchr(buf, '\n') != NULL)
			break ;
	}

	if (processnewline(saved, line) == 1 || processnewline(saved, line) == -1)
		return (1);
	if (processnewline(saved, line) == 0)
		return (0);

	//IF HAS NEW LINE, copy until the new line and save the line read to **line
	// new saved buffer
	//return 1

	//IF REMAINING SAVED HAS NO NEW LINE, copy saved to line 
	// delete saved
	// return 1 

	//IF SAVED HAS NOTHING, RETURN O - READING COMPLETE

	return (0);
}


int main(int argc, char **argv)
{
    int fd;
    char *line;

    fd = open(argv[1], O_RDONLY);
//    line = ft_memalloc(1000000);
//    line = "hello";
    if (argc != 2)
        printf("Invalid \n");
    if (argc == 2)
    {
        if (fd == -1)
        {
            printf("open () failed \n");
            return (1);
        }
        if (get_next_line(fd, &line) == 1)
		{
			printf("gnl successful \n");
			printf("print line: %s \n", line);
		}
    }
}
