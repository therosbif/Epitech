/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include "my.h"

int my_isint(char *nb)
{
    for (; *nb && *nb != '\n'; nb++) {
        if (*nb < '0' || *nb > '9')
            return 0;
    }
    return 1;
}
