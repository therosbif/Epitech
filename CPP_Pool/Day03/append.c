/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD03-jack.goodall
** File description:
** append
*/

#include "./string.h"

void append_c(string_t *this, const char *ap)
{
    char *new = my_strcat(this->str, ap);

    free(this->str);
    this->str = new;
}

void append_s(string_t *this, const string_t *ap)
{
    append_c(this, ap->str);
}

char at(const string_t *this, size_t pos)
{
    if (my_strlen(this->str) < pos - 1) return -1;
    return this->str[pos];
}

int size(const string_t *this)
{
    if (!this) return -1;
    return my_strlen(this->str);
}
