/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include "c_tools.h"

void my_error(char *str)
{
    write(2, str, my_strlen(str));
    exit(84);
}
