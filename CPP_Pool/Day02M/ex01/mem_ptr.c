/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02M-jack.goodall
** File description:
** mem_ptr
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mem_ptr.h"

void add_str(const char *str1, const char *str2, char **res)
{
    int i = 0;

    *res = malloc(strlen(strdup(str1)) + strlen(strdup(str2)) + 1);
    for (; i < strlen(str1); i++)
        (*res)[i] = str1[i];
    for (int j = 0; str2[j]; j++, i++)
        (*res)[i] = str2[j];
    (*res)[i] = 0;
}

void add_str_struct(str_op_t *str_op)
{
    add_str(str_op->str1, str_op->str2, &(str_op->res));
}
