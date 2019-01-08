/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** main
*/

#include "my.h"

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
        for (int j = 1; j < dt->length - nbrStars / 2; j++) {
            map[i][j] = ' ';
        }
        for (int j = dt->length - nbrStars / 2; j < dt->length - nbrStars / 2 + nbrStars; j++) {
            map[i][j] = '|';
        }
        for (int j = dt->length - nbrStars / 2 + nbrStars; j < dt->length - nbrStars / 2 + nbrStars + dt->length - nbrStars / 2 - 1; j++) {
            map[i][j] = ' ';
        }
        map[i][dt->length * 2] = '*';
        map[i][dt->length * 2 + 1] = '\n';
        nbrStars += 2;
    }
    for (int i = 0; i < dt->length + dt->length + 1; i++)
        map[dt->length + 1][i] = '*';
    map[dt->length + 1][dt->length + dt->length + 1] = '\n';
    return (map);
}

char **modify_map(char **map, struct data *dt)
{
    int i = 0;

    for (; i < dt->length + dt->length + 1 && map[dt->line][i] != '|'; i++);
    for (; i < dt->length + dt->length + 1; i++) {
        if (map[dt->line][i] == ' ' || map[dt->line][i] == '*') {
            while (dt->matches > 0) {
                i--;
                map[dt->line][i] = ' ';
                dt->matches--;
            }
            return (map);
        }
    }
    return (map);
}

void display_map(char **map)
{
    for (int i = 0; map[i][0] != '\0'; i++) {
        my_putstr(map[i]);
    }
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

int check_remaining_pipes(char **map, struct data *dt)
{
    for (int i = 1; i <= dt->length; i++) {
        for (int j = 1; j <= dt->length + 3; j++) {
            if (map[i][j] == '|')
                return (0);
        }
    }
    return (1);
}

int game_loop(char **map, struct data *dt)
{
    int game = 1;
    int loop = 1;

    dt->line = 0;
    dt->matches = 0;
    display_map(map);
    my_putstr("Your turn:\n");
    while (game) {
        while (loop) {
            my_putstr("Line: ");
            dt->line = my_getnbr(get_next_line(0));
            if (dt->line > dt->length || dt->line < 1) {
                my_putstr("Error: this line is out of range\n");
                break;
            }
            my_putstr("Matches: ");
            dt->matches = my_getnbr(get_next_line(0));
            if (dt->matches > nbr_pipes(map, dt->line) || dt->matches > dt->maxMatches || dt->matches < 1) {
                my_putstr("Error: you cannot remove more than ");
                my_put_nbr(dt->maxMatches);
                my_putstr(" matches per turn\n");
                break;
            }
            my_putstr("Player removed ");
            my_putchar(dt->matches + 48);
            my_putstr(" match(es) from line ");
            my_putchar(dt->line + 48);
            my_putchar('\n');
            map = modify_map(map, dt);
            if (check_remaining_pipes(map, dt) == 1) {
                game = 0;
                break;
            }
            display_map(map);
            my_putstr("Your turn:\n");
        }
    }
    return (0);
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
    game_loop(map, dt);
    return (0);
}