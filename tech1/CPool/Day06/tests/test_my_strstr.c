/*
** EPITECH PROJECT, 2019
** test
** File description:
** strstr
*/

#include <criterion/criterion.h>

Test(my_strstr, test_name)
{
    char src[6] = "Hello";
    char dest[3] = "ll";
    char *i = my_strstr(src, dest);

    cr_assert_eq(i, src + 2);
}
