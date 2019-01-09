/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** matchstick_map
*/

#include "my.h"

char **fill_pipes_spaces(char **map, int i, struct data *dt, int nbrStars)
{
    for (int j = 1; j < dt->length - nbrStars / 2; j++)
        map[i][j] = ' ';
    for (int j = dt->length - nbrStars / 2; j < dt->length -
        nbrStars / 2 + nbrStars; j++)
        map[i][j] = '|';
    for (int j = dt->length - nbrStars / 2 + nbrStars; j < dt->length -
        nbrStars / 2 + nbrStars + dt->length - nbrStars / 2 - 1; j++)
        map[i][j] = ' ';
    return (map);
}

char **create_map(struct data *dt)
{
    int nbrStars = 1;
    char **map = malloc(sizeof(char *) * (dt->length + 2));

    for (int i = 0; i <= dt->length + 2; i++)
        map[i] = malloc(sizeof(char) * (dt->length + dt->length + 2));
    for (int i = 0; i < dt->length + dt->length + 1; i++)
        map[0][i] = '*';
    map[0][dt->length * 2 + 1] = '\n';
    for (int i = 1; i <= dt->length; i++) {
        map[i][0] = '*';
        map = fill_pipes_spaces(map, i, dt, nbrStars);
        map[i][dt->length * 2] = '*';
        map[i][dt->length * 2 + 1] = '\n';
        nbrStars += 2;
    }
    for (int i = 0; i < dt->length + dt->length + 1; i++)
        map[dt->length + 1][i] = '*';
    map[dt->length + 1][dt->length + dt->length + 1] = '\n';
    return (map);
}

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

char **modify_map_ai(char **map, struct data *dt, struct a_intelligence *ai)
{
    int i = 0;

    for (; i < dt->length + dt->length + 1 && map[ai->line][i] != '|'; i++);
    for (; i < dt->length + dt->length + 1; i++) {
        if (map[ai->line][i] == ' ' || map[ai->line][i] == '*')
            return (remove_matches_ai(map, ai, i));
    }
    return (map);
}

char **modify_map(char **map, struct data *dt)
{
    int i = 0;

    for (; i < dt->length + dt->length + 1 && map[dt->line][i] != '|'; i++);
    for (; i < dt->length + dt->length + 1; i++) {
        if (map[dt->line][i] == ' ' || map[dt->line][i] == '*')
            return (remove_matches(map, dt, i));
    }
    return (map);
}

void display_map(char **map)
{
    for (int i = 0; map[i][0] != '\0'; i++) {
        my_putstr(map[i]);
    }
}