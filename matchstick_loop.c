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
    return (0);
}

int loop_matches(char **map, struct data *dt)
{
    int a = 84;

    while (a == 84) {
        a = game_matches(dt, map);
        if (a == 42)
            return (42);
    }
    return (0);
}

int loop(char **map, struct data *dt, struct a_intelligence *ai)
{
    int looper = 1;
    int a = 0;
    int b = 0;

    while (looper) {
        my_putstr("\nYour turn:\n");
        a = loop_line(map, dt);
        if (a == 84)
            return (2);
        else if (a == 42)
            return (42);
        b = loop_matches(map, dt);
        if (b == 84)
            return (2);
        else if (b == 42)
            return (42);
        map = game_update_player(dt, map);
        if (check_remaining_pipes(map, dt) == 1)
            return (2);
        display_map(map);
        map = ai_main(ai, dt, map);
        if (map == NULL)
            return (0);
        display_map(map);
    }
    return (1);
}