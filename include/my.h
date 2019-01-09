/*
** EPITECH PROJECT, 2018
** h
** File description:
** h
*/

#ifndef MY_H_
#define MY_H_
#ifndef READ_SIZE
#define READ_SIZE (8)

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>


struct data
{
    int length;
    int line;
    int matches;
    int maxMatches;
};

struct a_intelligence
{
    int line;
    int matches;
};


void my_putchar(char);
int my_put_nbr(int nb);
int my_str_isnum(char *str);
int my_getnbr(char *);
int my_strlen(char *);
int my_putstr(char const *);
char *get_next_line(int);
char **fill_pipes_spaces(char **map, int i, struct data *dt, int nbrStars);
char **create_map(struct data *dt);
char **modify_map(char **map, struct data *dt);
void display_map(char **map);
int game(char **map, struct data *dt);
int nbr_pipes(char **map, int line);
int check_remaining_pipes(char **map, struct data *dt);
char **ai_main(struct a_intelligence *ai, struct data *dt, char **map);
char **modify_map_ai(char **map, struct data *dt, struct a_intelligence *ai);
int check_remaining_on_line(int line, struct data *dt, char **map);

#endif //READ_SIZE
#endif //MY_H_
