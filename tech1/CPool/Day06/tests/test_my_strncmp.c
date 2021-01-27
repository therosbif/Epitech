/*
** EPITECH PROJECT, 2019
** test
** File description:
** strncmp
*/

#include <criterion/criterion.h>

Test(my_strncmp, test_name)
{
    char s1[6] = "Hello";
    char s2[6] = "Hello";
    int i = my_strncmp(s1, s2, 6);
    
    cr_assert_eq(i, 0);
}
