gcc -Wall -Wextra -Werror -o run *.c ./libft/*.c -g
valgrind --leak-check=full ./run testfiles/abc.txt