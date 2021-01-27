/*
** EPITECH PROJECT, 2019
** test
** File description:
** is lower
*/

#include <criterion/criterion.h>

Test(my_str_islower, test_name)
{
    cr_assert_eq(my_str_islower("defz"), 1);
}
