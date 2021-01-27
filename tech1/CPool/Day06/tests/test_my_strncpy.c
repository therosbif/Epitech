/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include <criterion/criterion.h>

Test(my_strncpy, test_name)
{
    char dest[6] = {0};
    my_strncpy(dest, "Hello World", 5);
    cr_assert_str_eq(dest, "Hello");
}
