/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:35:17 by aho               #+#    #+#             */
/*   Updated: 2017/12/11 23:01:06 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h" 
#include <stdio.h>
#include <assert.h>
/*
int main()
{
    char    *line;
    int     out;
    int     p[2];
    int     fd;
    int     ret;

    out = dup(1);
    pipe(p);

    fd = 1;
    dup2(p[1], fd);
    write(fd, "abcd\n", 5);
    write(fd, "efgh\n", 5);
    close(p[1]);
    dup2(out, fd);

    get_next_line(p[0], &line);
	printf("line:%s--\n", line);
    if (strcmp(line, "abcd") == 0)
		printf("abcd pass \n");
	else
		printf("abcd fail \n");

    get_next_line(p[0], &line);
	printf("line:%s--\n", line);
    if (strcmp(line, "efgh") == 0)
		printf("efgh pass \n");
	else
		printf("efgh fail \n");

    ret = get_next_line(p[0], &line);
    if(ret == 0)
		printf("ret == 0 \n");
	else
		printf("fail - ret should equal 0\n");
} 
*/
