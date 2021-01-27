/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD01-jack.goodall
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "menger.h"

int error_check(int ac, char const *av[])
{
    if (ac != 3)
        return 1;
    if (atoi(av[2]) < 1)
        return 2;
    if (atoi(av[1]) < 1 || atoi(av[1]) % (int)pow(3, atoi(av[2])))
        return 3;
    return 0;
}

int main(int ac, char const *av[])
{
    if (error_check(ac, av))
        return 84;
    menger(atoi(av[1]), atoi(av[2]), 0, 0);
    return 0;
}
