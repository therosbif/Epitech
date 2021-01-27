/*
** EPITECH PROJECT, 2019
** avanced sort array
** File description:
** sort
*/

#include "my.h"

int my_advanced_sort_word_array
(char **tab, int (*cmp)(char const *, char const *))
{
    char *temp;
    char sort = 1;

    while (sort) {
        sort = 0;
        for (int i = 0 ; tab[i + 1] != 0 ; i++) {
            if ((*cmp)(tab[i], tab[i + 1]) > 0) {
                temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
                sort = 1;
            }
        }
    }
    return (1);
}
