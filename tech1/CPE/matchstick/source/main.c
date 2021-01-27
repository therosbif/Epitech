/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** main
*/

#include "matchstick.h"

void show_map(char **map, int lines)
{
    for (int i = 0; i <= lines + 1; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
}

int nb_error(int nb, int total, int max)
{
    int valid = 1;

    (nb < 0) ? my_putstr(ERR_INV), valid = 0 : 1;
    (nb == 0 && valid) ? my_putstr(ERR_MINMATCH), valid = 0 : 1;
    if (nb > max && valid) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(max);
        my_putstr(" matches per turn\n");
        valid = 0;
    }
    (nb > total && valid) ? my_putstr(ERR_TOTALMATCH), valid = 0 : 1;
    return valid;
}

int error_check(int ac, char **av)
{
    if (ac != 3) {
        write(2, "ERROR: Wrong number of args\n", 28);
        return 84;
    }
    if ((!my_isint(av[1]) || !my_isint(av[2])) || (my_getnbr(av[1]) < 1 ||
        my_getnbr(av[2]) < 1)) {
        write(2, "ERROR: Args must be strictly positive ints\n", 44);
        return 84;
    }
    if (my_getnbr(av[1]) > 99 || my_getnbr(av[1]) < 2) {
        write(2, ERR_NLINES, 59);
        return 84;
    }
    return 0;
}

void my_freemap(char **map, int lines)
{
    for (int i = 0; i < lines + 2; i++)
        free(map[i]);
    free(map);
}

int main(int ac, char **av)
{
    char **map;
    int turn = 0;

    if (error_check(ac, av))
        return 84;
    map = malloc(sizeof(char *) * (my_getnbr(av[1]) + 3) + 2);
    map[0] = malloc(my_getnbr(av[1]) * 2 + 4);
    map = make_map(map, my_getnbr(av[1]));
    turn = game_loop(map, my_getnbr(av[1]), my_getnbr(av[2]));
    if (turn == -1) {
        my_freemap(map, my_getnbr(av[1]));
        return 0;
    }
    show_map(map, my_getnbr(av[1]));
    my_freemap(map, my_getnbr(av[1]));
    my_putstr((!turn) ? MSG_WIN : MSG_LOSE);
    return (turn) ? 2 : 1;
}
