/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** matchstick_game
*/

#include "my.h"

int game_line(struct data *dt, char **map)
{
    char *tmp;

    my_putstr("Line: ");
    tmp = get_next_line(0);
    if (tmp == NULL)
        return (42);
    if (my_str_isnum(tmp) != 0)
        dt->line = my_getnbr(tmp);
    else {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (84);
    }
    if (dt->line > dt->length || dt->line < 1 || check_remaining_on_line(dt->line, dt, map) == 0) {
        my_putstr("Error: this line is out of range\n");
        return (84);
    }
    return (0);
}

int game_matches(struct data *dt, char **map)
{
    char *tmp;

    my_putstr("Matches: ");
    tmp = get_next_line(0);
    if (tmp == NULL)
        return (42);
    if (my_str_isnum(tmp) != 0)
        dt->matches = my_getnbr(tmp);
    else {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (84);
    }
    if (dt->matches < 1) {
        my_putstr("Error: you have to remove at least one match\n");
        return (84);
    }
    if (dt->matches > nbr_pipes(map, dt->line)) {
        my_putstr("Error: not enough matches on this line\n");
        return (84);
    }
    if (dt->matches > dt->maxMatches) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(dt->maxMatches);
        my_putstr(" matches per turn\n");
        return (84);
    }
    return (0);
}

char **game_update_player(struct data *dt, char **map)
{
    my_putstr("Player removed ");
    my_put_nbr(dt->matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(dt->line);
    my_putchar('\n');
    map = modify_map(map, dt);
    return (map);
}

int game(char **map, struct data *dt)
{
    struct a_intelligence *ai = malloc(sizeof(struct a_intelligence));
    int game = 1;

    dt->line = 0;
    dt->matches = 0;
    display_map(map);
    while (game == 1)
        game = loop(map, dt, ai);
    if (game == 2) {
        my_putstr("You lost, too bad...\n");
        return (2);
    } else if (game == 1) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return (0);
}