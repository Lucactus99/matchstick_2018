##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC      =       gcc

SRC     =	main.c \
			src/my_putchar.c \
			src/my_putstr.c \
			src/my_getnbr.c \
			src/my_strlen.c \
			src/get_next_line.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       matchstick

CFLAGS  =       -W -Wall -Wextra -ansi -pedantic -g -std=c99 -I include

all:    $(NAME)

$(NAME):        $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
