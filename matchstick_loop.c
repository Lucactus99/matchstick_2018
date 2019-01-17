/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** matchstick_loop
*/

#include "my.h"

int loop_line(char **map, struct data *dt)
{
    int a = 84;

    while (a == 84) {
        a = game_line(dt, map);
        if (a == 42)
            return (42);
    }
    return (loop_matches(map, dt));
}

int loop_matches(char **map, struct data *dt)
{
    int a = 84;

    while (a == 84) {
        a = game_matches(dt, map);
        if (a == 42)
            return (42);
        if (a == 84)
            loop_line(map, dt);
    }
    return (0);
}

int return_value(int nb)
{
    if (nb == 84)
        return (2);
    else if (nb == 42)
        return (42);
    return (0);
}

int loop_2(char **map, struct data *dt, struct a_intelligence *ai)
{
    map = game_update_player(dt, map);
    if (check_remaining_pipes(map, dt) == 1)
        return (2);
    display_map(map);
    map = ai_main(ai, dt, map);
    if (map == NULL)
        return (0);
    display_map(map);
    return (-1);
}

int loop(char **map, struct data *dt, struct a_intelligence *ai)
{
    int looper = 1;
    int nb = 0;

    while (looper) {
        my_putstr("\nYour turn:\n");
        nb = loop_line(map, dt);
        if (return_value(nb) != 0)
            return (return_value(nb));
        nb = loop_2(map, dt, ai);
        if (nb >= 0)
            return (nb);
    }
    return (1);
}