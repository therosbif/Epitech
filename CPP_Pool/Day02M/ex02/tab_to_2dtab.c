/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02M-jack.goodall
** File description:
** tab_to_2dtab
*/

#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int pos_in_tab = 0;

    *res = malloc(sizeof(int *) * (length));
    for (int i = 0; i < length; i++) {
        (*res)[i] = malloc(sizeof(int) * (width));
        for (int j = 0; j < width; j++, pos_in_tab++)
            (*res)[i][j] = tab[pos_in_tab];
    }
}
