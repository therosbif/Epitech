/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD03-jack.goodall
** File description:
** split
*/

#include "string.h"

static void add_string_c(const string_t *this, int end, int begin,
    char **str)
{
    *str = malloc(this->size(this));
    this->copy(this, *str, end - begin, begin);
    (*str)[end - begin] = 0;
}

char **split_c(const string_t *this, char separator)
{
    char **tab;
    unsigned int counter = 0;

    for (int i = 0; this->str[i]; i++)
        counter += (this->str[i] == separator);
    tab = malloc((counter + 2) * sizeof(*tab));
    tab[counter + 1] = NULL;
    for (int end = 0, begin = 0, i = 0; 1; end++) {
        if (this->at(this, end) == separator) {
            add_string_c(this, end, begin, &(tab[i]));
            i++;
            begin = end + 1;
        } if (this->str[end] == 0) {
            add_string_c(this, end, begin, &(tab[i]));
            return tab;
        }
    }
}

static void add_string_s(const string_t *this, int end, int begin,
    string_t **str)
{
    char *tmp = malloc(this->size(this));

    *str = malloc(sizeof(**str));
    this->copy(this, tmp, end - begin, begin);
    tmp[end - begin] = 0;
    string_init(*str, tmp);
    free(tmp);
}

string_t **split_s(const string_t *this, char separator)
{
    string_t **tab;
    unsigned int counter = 0;

    for (int i = 0; this->str[i]; i++)
        counter += (this->str[i] == separator);
    tab = malloc((counter + 2) * sizeof(*tab));
    tab[counter + 1] = NULL;
    for (int end = 0, begin = 0, i = 0; 1; end++) {
        if (this->at(this, end) == separator) {
            add_string_s(this, end, begin, &(tab[i]));
            i++;
            begin = end + 1;
        } if (this->str[end] == 0) {
            add_string_s(this, end, begin, &(tab[i]));
            return tab;
        }
    }
}
