/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02M-jack.goodall
** File description:
** div
*/

#include "castmania.h"

int integer_div(int a, int b)
{
    return ((b == 0) ? 0 : a / b);
}

float decimale_div(int a, int b)
{
    return ((b == 0) ? 0 : (float)a / (float)b);
}

void exec_div(division_t *operation)
{
    if (operation->div_type == INTEGER)
        ((integer_op_t *)(operation->div_op))->res =
        integer_div(((integer_op_t *)(operation->div_op))->a,
        ((integer_op_t *)(operation->div_op))->b);
    else
        ((decimale_op_t *)(operation->div_op))->res =
        decimale_div(((decimale_op_t *)(operation->div_op))->a,
        ((decimale_op_t *)(operation->div_op))->b);
}
