/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:57:23 by aho               #+#    #+#             */
/*   Updated: 2017/11/28 22:22:50 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_SIZE 32

//Step by step tasks 
//1. read from file
//2. save what's in the file into a newly malloc'd string 
//3. split up what's being read

/*
char **save(char *buf)
{
	char *savedbuf;
	//only get the part after newline
	//if no newline, save it all

	return (savedbuf);
}


char **getlastsection(char *buf)
{



}


int hasnewline(char **line)
{


}
*/
/*
int get_next_line(const int fd, char **line) 
{
	char buf[BUFF_SIZE];
	int ret;

	char *ptr_to_line; 
	ptr_to_line = *line;
	line = ft_memalloc(1000000);
*/
//line - address of pointer to a character that will be used to save the line read from the file descriptor
//read, malloc, free

//5 functions
/*
	int ret;
	char buf[BUF_SIZE];
	char remainder[getremaininglength];
*/
	/*
	if (fd == 3)
	{
		printf("file successfully opened\n inside getnextline() \n");

		printf("printing line: %s \n", *line);


		while ((ret = read(fd, buf, BUFF_SIZE))) //keep reading
		{
			buf[ret] = '\0';

			ft_putstr("ret: ");
			ft_putnbr(ret);
			ft_putchar('\n');
			ft_putstr(buf);
			ft_putchar('\n');
	*/
//			printf("printing buf: %s \n", buf);
		
//			line = line + buf;

/*			if (hasnewline(buf) == 1)
			{
				line = remainder + getlastsection(buf); //save the part
				remainder = saved(buf);
			}
			else 
			{
				remainder = remainder + saved(buf);
			}
*/
	//		}

	//	}

	//line has been read
//	return (1);
//address of a pointer to a character that will be used to save the line read from the fd

//return 1, 0, -1
// 1 - line has been read 
// 0 - reading has been completed 
// -1 - error
//}



/*

int main(int argc, char **argv)
{
    int fd;
//  int ret;
//  char buf[BUFF_SIZE];

    char *line;
    fd = open(*argv, O_RDONLY);
    line = ft_memalloc(10);
    line = "hello";

    if (argc != 2)
        printf("Invalid \n");

    if (argc == 2)
    {
        if (fd == -1)
        {
            printf("open () failed \n");
            return (1);
        }

        get_next_line(fd, &line);
        //print the line
        //call get_next_line within a function that reads a file



    }

}



*/
