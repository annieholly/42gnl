#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aho <aho@student.42.us.org>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 15:46:44 by aho               #+#    #+#              #
#    Updated: 2017/11/28 16:00:22 by aho              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES =	ft_bzero 	/
		ft_memalloc	/
		ft_memset	/
		ft_putchar 	/
		ft_putstr	/
		ft_putnbr	/
		ft_strjoin	/
		ft_strnew	/
		ft_strlen	/

SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): 
	@$(CC) $(CFLAGS) $(SRC) -I ./ 
	@ar rcs $(NAME) $(OBJ)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all