##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

.RECIPEPREFIX +=

CC      =       gcc

SRC     =	matchstick_main.c \
            matchstick_map.c \
            matchstick_game.c \
            matchstick_ai.c \
            matchstick_check.c \
            matchstick_loop.c \
            matchstick_get_info.c \
            src/my_putchar.c \
            src/my_putstr.c \
            src/my_getnbr.c \
            src/get_next_line.c \
            src/my_put_nbr.c \
            src/my_str_isnum.c

OBJ     =       $(SRC:.c=.o)

NAME    =		matchstick

CFLAGS  =       -W -Werror -Wextra -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable -ansi -pedantic -g -std=c99 -I ./include

all:    $(NAME)

$(NAME):        $(OBJ)
    $(CC) $(OBJ) -o $(NAME) $(CFLAGS)
    rm -f $(OBJ)

clean:
    rm -f $(OBJ)

fclean:	clean
    rm -f $(NAME)

re:     fclean all
