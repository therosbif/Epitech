/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD03-jack.goodall
** File description:
** to_int
*/

#include "./string.h"
#include <unistd.h>

int to_int(const string_t *this)
{
    return atoi(this->str);
}

void print(const string_t *this)
{
    write(1, this->str, this->size(this));
}

string_t *substr(const string_t *this, int offset, int length)
{
    string_t *sub = malloc(sizeof(*sub));
    size_t str_size;
    size_t pos;
    char* str;

    if (offset >= 0) {
        pos = ((length >= 0) ? offset : offset + length);
        str_size = ((length >= 0) ? MIN(length, this->size(this) - offset) :
            MIN(this->size(this) - offset - length, ABS(length)));
    } else {
        pos = ((length >= 0) ? this->size(this) + offset :
            this->size(this) + offset + length);
        str_size = ((length >= 0) ? MIN(length, -offset) :
            MIN(-offset - length, ABS(length)));
    }
    str = malloc(str_size + 1);
    str[str_size] = 0;
    this->copy(this, str, str_size - 1, pos);
    string_init(sub, str);
    free(str);
    return sub;
}
