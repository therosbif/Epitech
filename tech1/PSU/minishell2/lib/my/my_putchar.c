/*
** EPITECH PROJECT, 2019
** my put char
** File description:
** print a character
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
