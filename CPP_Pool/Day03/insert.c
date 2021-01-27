/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD03-jack.goodall
** File description:
** insert
*/

#include "string.h"

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *save;

    if (pos > this->size(this)) return this->append_c(this, str);
    save = malloc(this->size(this) + my_strlen(str) + 1);
    this->copy(this, save, pos, 0);
    my_strcpy(save + pos, str);
    my_strcpy(save + pos + my_strlen(str), this->str + pos);
    this->assign_c(this, save);
    free(save);
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    insert_c(this, pos, str->str);
}
