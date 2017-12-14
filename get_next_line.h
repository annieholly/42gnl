/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 01:25:10 by aho               #+#    #+#             */
/*   Updated: 2017/12/14 13:56:04 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

# define BUFF_SIZE 42

int get_next_line(const int fd, char **line);

#endif
