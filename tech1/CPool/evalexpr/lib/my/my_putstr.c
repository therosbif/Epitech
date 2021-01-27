/*
** EPITECH PROJECT, 2019
** put str
** File description:
** print a str
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
