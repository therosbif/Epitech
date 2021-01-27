/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD03-jack.goodall
** File description:
** compare
*/

#include "./string.h"

int compare_c(const string_t *this, const char *str)
{
    return my_strcmp(this->str, str);
}

int compare_s(const string_t *this, const string_t *str)
{
    return compare_c(this, str->str);
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t i = 0;

    for ( ; this->str[pos + i] && i < n ; i++)
        s[i] = this->str[i + pos];
    s[i] = this->str[i + pos];
    return (i);
}
