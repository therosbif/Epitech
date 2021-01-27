/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02A-jack.goodall
** File description:
** value_stack
*/

#include "stack.h"

void *stack_top(stack_t stack)
{
    return list_get_elem_at_front(stack);
}
