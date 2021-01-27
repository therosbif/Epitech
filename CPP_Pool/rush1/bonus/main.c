/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush1-jack.goodall
** File description:
** main
*/

#include "my_string.h"
#include <stdio.h>

int main(void)
{
    Object *str1 = new(String, "Hello ");
    Object *str2 = new(String, "42");
    Object *str3 = new(String, "lo");
    Object *str4 = new(String, "World!");
    char *test;

    cat(str1, str4);

    test = str(str1);
    printf("str(str1): %s\n", test);
    free(test);

    printf("len(str1): %d\n", len(str1));
    printf("find(str1, str3): %d\n", find(str1, str3));
    printf("toi(str2): %d\n", toi(str2));

    cpy_c(str1, "42");
    test = str(str1);

    printf("cpy(str1, str2): %s\n", test);
    printf("cmp(str1, str2): %d\n", cmp(str1, str2));

    delete(str1);
    delete(str2);
    delete(str3);
    delete(str4);
    free(test);
    return 0;
}
