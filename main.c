/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:35:17 by aho               #+#    #+#             */
/*   Updated: 2017/12/13 18:57:03 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h" 
#include <stdio.h>
#include <assert.h>


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
//          printf("\n>>gnl returned 1 - gnl  successful!\n");
			ft_putendl(line);
            free(line);
        }
    }

//	while (1)
//	{
//	}
}
