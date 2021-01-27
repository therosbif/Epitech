/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#ifndef COUNT_WORDS_H_
#define COUNT_WORDS_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct words{
    char *word;
    int nb;
    struct words *next;
} words_t;

char *my_strdup(char *str);
int my_strcmp(char const *s1, char const *s2);

#endif
