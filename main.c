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
    printf("%d\n", i);
    for (; i < dt->length + dt->length + 1; i++) {
        if (map[dt->line][i] == ' ' || map[dt->line][i] == '*') {
            while (dt->matches > 0) {
                printf("ok\n");
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

int game_loop(char **map, struct data *dt)
{
    int loop = 1;

    dt->line = 0;
    dt->matches = 0;
    while (loop) {
        for (int i = 0; i < 3; i++) {
            display_map(map);
            my_putstr("Your turn:\n");
            my_putstr("Line: ");
            dt->line = my_getnbr(get_next_line(0));
            my_putstr("Matches: ");
            dt->matches = my_getnbr(get_next_line(0));
            my_putstr("Player removed ");
            my_putchar(dt->matches + 48);
            my_putstr(" match(es) from line ");
            my_putchar(dt->line + 48);
            my_putchar('\n');
            map = modify_map(map, dt);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    struct data *dt = malloc(sizeof(struct data));
    dt->length = my_getnbr(av[1]);
    char **map = create_map(dt);

    if (ac < 3)
        return (84);
    game_loop(map, dt);
    return (0);
}