
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aho <aho@student.42.us.org>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 15:40:16 by aho               #+#    #+#              #
#    Updated: 2017/11/28 22:03:58 by aho              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = getnextline

LIBFT = libft/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

FILES = get_next_line 

SRC = $(addsuffix .c, $(FILES))
SRC = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all