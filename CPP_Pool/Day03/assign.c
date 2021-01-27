/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD03-jack.goodall
** File description:
** assign
*/

#include "./string.h"

void assign_s(string_t *this, const string_t *str)
{
    free(this->str);
    this->str = my_strdup(str->str);
}

void assign_c(string_t *this, const char *s)
{
    free(this->str);
    this->str = my_strdup(s);
}

void clear(string_t *this)
{
    free(this->str);
    this->str = my_strdup("\0");
}
