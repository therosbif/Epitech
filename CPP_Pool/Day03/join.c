/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD03-jack.goodall
** File description:
** join
*/

#include "string.h"

void join_c(string_t *this, char delim, const char * const *tab)
{
    char *tmp = malloc(2);

    tmp[0] = delim;
    tmp[1] = 0;
    this->assign_c(this, "");
    for (int i = 0; tab[i]; i++) {
        this->append_c(this, tab[i]);
        if (tab[i + 1]) this->append_c(this, tmp);
    }
    free(tmp);
}

void join_s(string_t *this, char delim, const string_t * const *tab)
{
    char *tmp = malloc(2);

    tmp[0] = delim;
    tmp[1] = 0;
    this->assign_c(this, "");
    tab[0]->print;
    for (int i = 0; tab[i]; i++) {
        this->append_s(this, tab[i]);
        if (tab[i + 1]) this->append_c(this, tmp);
    }
    free(tmp);
}
