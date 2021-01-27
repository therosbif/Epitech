/*
** EPITECH PROJECT, 2019
** str into words
** File description:
** converts str to words
*/

#include <stdlib.h>
#include "my.h"

int my_is_num(char c);
int my_is_opp(char c);

int my_isalphanum(char c)
{
    if (my_is_opp(c) || my_is_num(c))
            return (1);
    return (0);
}

int count_words(char const *str)
{
    int n = 0;
    int i = 0;

    for ( ; !(my_isalphanum(str[i])) ; i++);
    for ( ; str[i] != '\0' ; i++) {
        if (!(my_isalphanum(str[i])) && my_isalphanum(str[i + 1]))
            n++;
    }
    return (n + 1);
}

char **copy_over(char const *str, char **dest)
{
    int prev = 0;
    int j = 0;
    int i = 0;
    int k = -1;

    for ( ; !(my_isalphanum(str[i])) ; i++, prev = i);
    for (; str[i] != '\0' ; i++) {
        if (!(my_isalphanum(str[i])))
            k++;
        if (!(my_isalphanum(str[i])) && my_isalphanum(str[i + 1])) {
            my_strncpy(dest[j], str + prev, i - prev - k);
            j++;
            k = -1;
            prev = i + 1;
        }
    }
    for (i = 0 ; my_isalphanum(str[prev + i]) ; i++);
    my_strncpy(dest[j], str + prev, i);
    dest[j][i] = 0;
    dest[j + 1] = 0;
    return (dest);
}

char **my_str_to_word_array(char const *str)
{
    int j = 0;
    int k = 0;
    int i = 0;
    int words = count_words(str);
    char **dest = malloc(sizeof(char *) * (words + 1));

    for ( ; !(my_isalphanum(str[i])) ; i++);
    for ( ; str[i] != '\0' ; i++) {
        if (my_isalphanum(str[i]))
            j++;
        if (!(my_isalphanum(str[i])) && my_isalphanum(str[i + 1])) {
            dest[k] = malloc(j + 1);
            j = 0;
            k++;
        }
    }
    dest[k] = malloc(sizeof(char *));
    return (copy_over(str, dest));
}
