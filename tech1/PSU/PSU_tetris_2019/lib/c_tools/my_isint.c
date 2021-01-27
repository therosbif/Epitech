/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include "c_tools.h"

int my_isint(char *nb)
{
    for (; *nb; nb++) {
        if ((*nb < '0' || *nb > '9') && *nb != '-' && *nb != '+')
            return 0;
    }
    return 1;
}
