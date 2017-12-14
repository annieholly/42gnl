#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aho <aho@student.42.us.org>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 15:46:44 by aho               #+#    #+#              #
#    Updated: 2017/12/14 14:11:01 by aho              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES =	ft_bzero 	\
		ft_memalloc	\
		ft_memmove	\
		ft_memset	\
		ft_putchar 	\
		ft_putendl	\
		ft_putnbr 	\
		ft_putstr	\
		ft_strcat	\
		ft_strchr	\
		ft_strclr	\
		ft_strcmp	\
		ft_strdel	\
		ft_strdup	\
		ft_strjoin	\
		ft_strlen	\
		ft_strnew	\
		ft_strsub	\
		ft_strcpy	\

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