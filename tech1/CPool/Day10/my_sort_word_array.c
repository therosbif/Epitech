/*
** EPITECH PROJECT, 2019
** sort array
** File description:
** sorts word array
*/

#include "my.h"

int my_sort_word_array(char **tab)
{
    char *temp;
    char sort = 1;

    while (sort) {
        sort = 0;
        for (int i = 0 ; tab[i + 1] != 0 ; i++) {
            if (my_strcmp(tab[i], tab[i + 1]) > 0) {
                temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
                sort = 1;
            }
        }
    }
    return (1);
}
