/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick_main
*/

#include "my.h"

char **remove_matches_ai(char **map, struct a_intelligence *ai, int i)
{
    while (ai->matches > 0) {
        i--;
        map[ai->line][i] = ' ';
        ai->matches--;
    }
    return (map);
}

char **remove_matches(char **map, struct data *dt, int i)
{
    while (dt->matches > 0) {
        i--;
        map[dt->line][i] = ' ';
        dt->matches--;
    }
    return (map);
}

int randomize(int min, int max)
{
    return ((rand() % (max + 1 - min)) + min);
}

int nbr_pipes(char **map, int line)
{
    int nbr = 0;

    for (int j = 0; map[line][j] != '\n'; j++) {
        if (map[line][j] == '|')
            nbr++;
    }
    return (nbr);
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