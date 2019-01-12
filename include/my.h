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
int my_put_nbr(int);
int my_str_isnum(char *);
int my_getnbr(char *);
int my_strlen(char *);
int my_putstr(char const *);
char *get_next_line(int);
char **fill_pipes_spaces(char **, int , struct data *, int);
char **create_map(struct data *);
char **modify_map(char **, struct data *);
void display_map(char **);
int game(char **, struct data *);
int nbr_pipes(char **, int);
int check_remaining_pipes(char **, struct data *);
char **ai_main(struct a_intelligence *, struct data *, char **);
char **modify_map_ai(char **, struct data *, struct a_intelligence *);
int check_remaining_on_line(int , struct data *, char **);
int randomize(int, int);
int check_errors(int, char **);
int loop(char **, struct data *, struct a_intelligence *);
int game_line(struct data *, char **);
int game_matches(struct data *, char **);
char **game_update_player(struct data *, char **);
char **remove_matches(char **, struct data *, int);
char **remove_matches_ai(char **, struct a_intelligence *, int);

#endif //READ_SIZE
#endif //MY_H_
