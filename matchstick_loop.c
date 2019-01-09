/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** matchstick_loop
*/

#include "my.h"

int loop_line(char **map, struct data *dt)
{
    while (game_line(dt) == 84) {
        if (check_remaining_pipes(map, dt) == 1)
            return (2);
    }
    return (0);
}

int loop_matches(char **map, struct data *dt)
{
    while (game_matches(dt, map) == 84)
        if (loop_line(map, dt) == 2)
            return (2);
    return (0);
}

int loop(char **map, struct data *dt, struct a_intelligence *ai)
{
    int looper = 1;

    while (looper) {
        my_putstr("\nYour turn:\n");
        if (loop_line(map, dt) == 84)
            return (2);
        if (loop_matches(map, dt) == 84)
            return (2);
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