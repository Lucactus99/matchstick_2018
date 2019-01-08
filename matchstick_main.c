/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick_main
*/

#include "my.h"

int nbr_pipes(char **map, int line)
{
    int nbr = 0;

    for (int j = 0; map[line][j] != '\n'; j++) {
        if (map[line][j] == '|')
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
    for (int i = 1; i < ac; i++) {
        if (my_str_isnum(av[i]) == 0)
            return (84);
    }
    if (ac != 3)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    struct data *dt = malloc(sizeof(struct data));
    char **map;

    dt->length = my_getnbr(av[1]);
    dt->maxMatches = my_getnbr(av[2]);
    if (check_errors(ac, av) == 84)
        return (84);
    else
        map = create_map(dt);
    game(map, dt);
    return (0);
}