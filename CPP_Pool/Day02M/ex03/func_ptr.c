/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02M-jack.goodall
** File description:
** func_ptr
*/

#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    int i = strlen(str) -1;

    for (; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
}

void print_upper(const char *str)
{
    for (int i = 0; str[i]; i++)
        printf("%c", str[i] - ((str[i] > 96 && str[i] < 123) ? 32 : 0));
    printf("\n");
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*funcs[4])() = {print_normal, print_reverse, print_upper, print_42};

    (*funcs[action])(str);
}
