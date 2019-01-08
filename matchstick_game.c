/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** matchstick_game
*/

#include "my.h"

int game_line(struct data *dt)
{
    my_putstr("Line: ");
    dt->line = my_getnbr(get_next_line(0));
    if (dt->line > dt->length || dt->line < 1) {
        my_putstr("Error: this line is out of range\n");
        return (84);
    }
    return (0);
}

int game_matches(struct data *dt, char **map)
{
    my_putstr("Matches: ");
    dt->matches = my_getnbr(get_next_line(0));
    if (dt->matches > nbr_pipes(map, dt->line) ||
    dt->matches > dt->maxMatches || dt->matches < 1) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(dt->maxMatches);
        my_putstr(" matches per turn\n");
        return (84);
    }
    return (0);
}

char **game_update(struct data *dt, char **map)
{
    my_putstr("Player removed ");
    my_putchar(dt->matches + 48);
    my_putstr(" match(es) from line ");
    my_putchar(dt->line + 48);
    my_putchar('\n');
    map = modify_map(map, dt);
    return (map);
}

int loop(char **map, struct data *dt)
{
    int loop = 1;

    while (loop) {
        if (game_line(dt) == 84)
            return (84);
        if (game_matches(dt, map) == 84)
            return (84);
        map = game_update(dt, map);
        if (check_remaining_pipes(map, dt) == 1)
            return (0);
        display_map(map);
        my_putstr("Your turn:\n");
    }
    return (1);
}

int game(char **map, struct data *dt)
{
    int game = 1;

    dt->line = 0;
    dt->matches = 0;
    display_map(map);
    my_putstr("Your turn:\n");
    while (game) {
        if (loop(map, dt) == 0)
            break;
    }
    return (0);
}