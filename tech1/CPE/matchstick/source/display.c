/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include "matchstick.h"

void disp_pick(int *coords, int turn)
{
    my_putstr((turn) ? "AI removed " : "Player removed ");
    my_put_nbr(coords[1]);
    my_putstr(" match(es) from line ");
    my_put_nbr(coords[0]);
    my_putchar('\n');
}

