/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:35:17 by aho               #+#    #+#             */
/*   Updated: 2017/12/11 22:57:16 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h" 
#include <stdio.h>
#include <assert.h>

/*
int main()
{

//	static void simple_string(t_test *test)
//	{
		char *line;
		int out;
		int p[2];
		int fd;

		out = dup(1);
		pipe(p);

		fd = 1;
		dup2(p[1], fd);
		write(fd, "abcdefgh\n", 9);
		write(fd, "ijklmnop\n", 9);
		write(fd, "qrstuvwx\n", 9);
		write(fd, "yzabcdef\n", 9);
		write(fd, "ghijklmn\n", 9);
		write(fd, "opqrstuv\n", 9);
		write(fd, "wxyzabcd\n", 9);
		close(p[1]);
		dup2(out, fd);




		get_next_line(p[0], &line);
		if (strcmp(line, "abcdefgh") == 0)
			printf("PASS 1\n");
		else
			printf("FAIL 1\n");
		
		get_next_line(p[0], &line);
		if (strcmp(line, "ijklmnop") == 0)
			printf("PASS 2\n");
		else
			printf("FAIL 2\n");

		get_next_line(p[0], &line);
		if (strcmp(line, "qrstuvwx") == 0)
			printf("PASS 3\n");
		else
			printf("FAIL 3\n");

		get_next_line(p[0], &line);
		if (strcmp(line, "yzabcdef") == 0)
			printf("PASS 4\n");
		else
			printf("FAIL 4\n");

		get_next_line(p[0], &line);
		if (strcmp(line, "ghijklmn") == 0)
			printf("PASS 5\n");
		else
			printf("FAIL 5\n");

		get_next_line(p[0], &line);
		if (strcmp(line, "opqrstuv") == 0)
			printf("PASS 6\n");
		else
			printf("FAIL 6\n");

		get_next_line(p[0], &line);
		if (strcmp(line, "wxyzabcd") == 0)
			printf("PASS 7\n");
		else
			printf("FAIL 7\n");



}
*/
