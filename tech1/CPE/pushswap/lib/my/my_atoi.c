/*
** EPITECH PROJECT, 2019
** get nbr
** File description:
** convert str to int
*/

int my_atoi(char *str)
{
    char sign = 1;
    int nb = 0;

    if (str[0] == '-') {
        str++;
        sign = -1;
    }
    for (; *str; str++)
        nb = nb * 10 + *str - 48;
    return (nb * sign);
}
