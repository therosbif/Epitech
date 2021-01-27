/*
** EPITECH PROJECT, 2019
** strlen
** File description:
** length of str
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    for ( ; str[i] != '\0' ; i++) {}
    return (i);
}
