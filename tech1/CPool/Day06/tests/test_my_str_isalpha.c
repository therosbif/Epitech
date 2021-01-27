/*
** EPITECH PROJECT, 2019
** test
** File description:
** is alpha
*/

#include <criterion/criterion.h>

Test(my_str_isalpha, test_name)
{
    cr_assert_eq(my_str_isalpha(""), 1);
}
