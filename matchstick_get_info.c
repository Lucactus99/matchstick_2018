/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** matchstick_get_info
*/

#include "my.h"

int get_nbr_matches_line(char **map, int i)
{
    int nbr = 0;

    for (int j = 0; map[i][j] != '\0'; j++) {
        if (map[i][j] == '|')
            nbr++;
    }
    return (nbr);
}

int get_nbr_matches(char **map)
{
    int nbr = 0;

    for (int i = 0; map[i][0] != '\0'; i++) {
        nbr += get_nbr_matches_line(map, i);
    }
    return (nbr);
}