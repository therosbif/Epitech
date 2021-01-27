/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02A-jack.goodall
** File description:
** modification_stack
*/

#include "stack.h"

bool stack_push(stack_t *stack_ptr, void *elem)
{
    return list_add_elem_at_front(stack_ptr, elem);
}

bool stack_pop(stack_t *stack_ptr)
{
    return list_del_elem_at_front(stack_ptr);
}
