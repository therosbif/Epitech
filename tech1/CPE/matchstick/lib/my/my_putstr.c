/*
** EPITECH PROJECT, 2019
** put str
** File description:
** print a str
*/

#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (0);
}
