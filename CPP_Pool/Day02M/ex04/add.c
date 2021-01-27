/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02M-jack.goodall
** File description:
** add
*/

#include "castmania.h"

int normal_add(int a, int b)
{
    return a + b;
}

int absolute_add(int a, int b)
{
    return (((a > 0) ? a : -a) + ((b > 0) ? b : -b));
}

void exec_add(addition_t *operation)
{
    if (operation->add_type == NORMAL)
        (&operation->add_op)->res =
            normal_add((&operation->add_op)->a, (&operation->add_op)->b);
    else
        (&operation->add_op)->res =
            absolute_add((&operation->add_op)->a, (&operation->add_op)->b);
}
