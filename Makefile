
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aho <aho@student.42.us.org>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 15:40:16 by aho               #+#    #+#              #
#    Updated: 2017/11/28 15:51:51 by aho              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = getnextline

CC = gcc

CFLAGS = -Wall -Werror -Wextra

FILES = get_next_line

SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME):
	@make -C libft/ re
	@$(CC) $(CFLAGS) -c $(SRC) -I libft/
	@$(CC) $(CFLAGS) -o $(NAME) main.c $(OBJ) -L libft/ -lft

clean:
	@make -C libft/ fclean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all