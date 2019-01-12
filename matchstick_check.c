/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** matchstick_check
*/

#include "my.h"

int check_remaining_on_line(int line, struct data *dt, char **map)
{
    int nbr = 0;

    for (int i = 1; i <= dt->length + 3; i++) {
        if (map[line][i] == '|')
            nbr++;
    }
    return (nbr);
}

int check_remaining_pipes_2(char **map, struct data *dt, int i)
{
    for (int j = 1; j <= dt->length + 3; j++) {
        if (map[i][j] == '|')
            return (0);
    }
    return (1);
}

int check_remaining_pipes(char **map, struct data *dt)
{
    for (int i = 1; i <= dt->length; i++)
        if (check_remaining_pipes_2(map, dt, i) == 0)
            return (0);
    return (1);
}

int check_errors(int ac, char **av)
{
    if (ac != 3)
        return (84);
    for (int i = 1; i < ac; i++) {
        if (my_str_isnum(av[i]) == 0)
            return (84);
    }
    return (0);
}