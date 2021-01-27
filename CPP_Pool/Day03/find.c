/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD03-jack.goodall
** File description:
** find
*/

#include "./string.h"

const char *c_str(const string_t *this)
{
    return my_strdup(this->str);
}

int empty(const string_t *this)
{
    return (my_strlen(this->str) == 0);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *res;

    if (pos > my_strlen(this->str)) return -1;
    res = my_strstr(this->str + pos, str);
    return ((res) ? (int)(res - this->str) : -1);
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    return find_c(this, str->str, pos);
}
