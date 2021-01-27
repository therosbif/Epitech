/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02M-jack.goodall
** File description:
** ptr_tricks
*/

#include "ptr_tricks.h"
#include <stdio.h>

int get_array_nb_elem(const int *ptr1, const int *ptr2)
{
    return (((ptr1 > ptr2) ? ptr1 : ptr2) - ((ptr1 < ptr2) ? ptr1 : ptr2));
}

whatever_t *get_struct_ptr(const int *member_ptr)
{
    void *tmp = member_ptr;

    return member_ptr - (&(((whatever_t *)tmp)->member) - member_ptr);
}
