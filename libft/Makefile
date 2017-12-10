#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aho <aho@student.42.us.org>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 15:46:44 by aho               #+#    #+#              #
#    Updated: 2017/12/09 21:56:15 by aho              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES =	ft_bzero 	\
		ft_memalloc	\
		ft_memset	\
		ft_memmove	\
		ft_putchar 	\
		ft_putstr	\
		ft_putnbr	\
		ft_strcat	\
		ft_strchr	\
		ft_strjoin	\
		ft_strnew	\
		ft_strlen	\
		ft_strdel	\
		ft_strsub	\
		ft_putendl	\

SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -I ./ -c

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all