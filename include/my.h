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
};


void my_putchar(char);
int my_getnbr(char *);
int my_strlen(char *);
int my_putstr(char const *);
char *get_next_line(int);

#endif //READ_SIZE
#endif //MY_H_
