/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** matchstick_ai
*/

#include "my.h"

int only_one_line_remaining(char **map, struct data *dt)
{
    int nbr = 0;

    if (check_remaining_pipes(map, dt) == 1)
        return (0);
    for (int i = 1; i <= dt->length; i++)
        if (check_remaining_on_line(i, dt, map) > 0)
            nbr++;
    return (nbr);
}

char **game_update_ai(struct a_intelligence *ai, char **map, struct data *dt)
{
    my_putstr("AI removed ");
    my_put_nbr(ai->matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(ai->line);
    my_putchar('\n');
    map = modify_map_ai(map, dt, ai);
    return (map);
}

int ai_line(struct a_intelligence *ai, struct data *dt, char **map)
{
    ai->line = 1;

    while (check_remaining_on_line(ai->line, dt, map) == 0) {
        ai->line = randomize(1, dt->length);
        if (check_remaining_pipes(map, dt) == 1)
            return (1);
    }
    return (0);
}

void ai_matches(struct a_intelligence *ai, struct data *dt, char **map)
{
    if (only_one_line_remaining(map, dt) == 1) {
        if (check_remaining_on_line(ai->line, dt, map) <= dt->maxMatches)
            ai->matches = check_remaining_on_line(ai->line, dt, map) - 1;
    } else
        ai->matches = randomize(1, dt->maxMatches);
    if (ai->matches == 0)
        ai->matches = 1;
}

char **ai_main(struct a_intelligence *ai, struct data *dt, char **map)
{
    my_putstr("\nAI's turn...\n");
    if (ai_line(ai, dt, map) == 1)
        return (NULL);
    ai_matches(ai, dt, map);
    map = game_update_ai(ai, map, dt);
    if (check_remaining_pipes(map, dt) == 1)
        return (NULL);
    return (map);
}