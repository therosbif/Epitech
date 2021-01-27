/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD03-jack.goodall
** File description:
** string
*/

#include "./string.h"

void string_init2(string_t *this)
{
    this->find_s = find_s;
    this->find_c = &find_c;
    this->insert_s = &insert_s;
    this->insert_c = &insert_c;
    this->to_int = &to_int;
    this->split_s = &split_s;
    this->split_c = &split_c;
    this->print = &print;
    this->join_s = &join_s;
    this->join_c = &join_c;
    this->substr = &substr;
}

void string_init(string_t *this, const char *s)
{
    this->str = my_strdup(s);
    this->assign_c = &assign_c;
    this->assign_s = &assign_s;
    this->append_c = &append_c;
    this->append_s = &append_s;
    this->at = &at;
    this->clear = &clear;
    this->size = &size;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    string_init2(this);
}

void string_destroy(string_t *this)
{
    free(this->str);
}
