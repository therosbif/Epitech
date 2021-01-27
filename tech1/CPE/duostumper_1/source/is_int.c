/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include "fractals.h"

int count_char_instr(char *str, char c)
{
    int i = 0;

    for (; *str; str++) {
        i += (*str == c);
    }
    return i;
}

int is_int(char *str)
{
    for (; *str; str++) {
        if (*str > '9' || *str < '0') {
            write(2, "ERROR: arg 1 must be int.\n", 26);
            return 0;
        }
    }
    return 1;
}

int is_valid_chars(char *str)
{
    for (; *str; str++) {
        if (*str != '#' && *str != '.' && *str != '@') {
            write(2, "ERROR: args 2 and 3 must contain only #, . and @\n", 49);
            return 0;
        }
    }
    return 1;
}

void free_arr(char **arr)
{
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}
