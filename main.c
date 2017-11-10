 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 01:34:19 by aho               #+#    #+#             */
/*   Updated: 2017/11/09 16:01:06 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_SIZE 32
/*
int main(int argc, char **argv)
{
	int fd; 
    char buf[BUFF_SIZE];
    int ret;

	if (argc != 2) 
		printf("Incorrect number of arguments \n");

	fd = open(argv[1], O_RDONLY);

    if (fd == -1)
    {
        ft_putstr("open() failed \n");
        return (1);
    }

    if (fd == 3)
    {
        while ((ret = read(fd, buf, BUFF_SIZE))) //keep reading
        {
            buf[ret] = '\0';

            ft_putstr("ret: ");
            ft_putnbr(ret);
            ft_putchar('\n');
            ft_putstr(buf);
            ft_putchar('\n');
        }

    }
}

*/
