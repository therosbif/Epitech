/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02A-jack.goodall
** File description:
** information_stack
*/

#include "stack.h"

unsigned int stack_get_size(stack_t stack)
{
    return list_get_size(stack);
}

bool stack_is_empty(stack_t stack)
{
    return list_is_empty(stack);
}
