/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** find a number in a string
*/

int my_getnbr(char *str)
{
    int res = 0;
    int sign = 0;
    int i = 0;

    ((str[i] == '-') ? (sign = 1, i++) : (0));
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            res *= 10;
            res += str[i] - '0';
        }
        else
            return (res);
        i++;
    }
    if (sign == 0)
        return (res);
    else
        return (-res);
}