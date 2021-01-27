/*
** EPITECH PROJECT, 2019
** convert
** File description:
** dec to any and any to dec
*/

#include <stdlib.h>
#include "my.h"

char *convert(char *base, unsigned long num)
{
    int b = my_strlen(base);
    char *dest = malloc(65);
    int i = 0;

    for (; num ; i++) {
        dest[i] = base[num % b];
        num /= b; 
    }
    dest[i] = 0;
    my_revstr(dest);
    for (; dest[0] == '0' && dest[1] != 0; dest++);
    return dest;
}