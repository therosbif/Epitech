/*
** EPITECH PROJECT, 2019
** test
** File description:
** printable
*/

#include <criterion/criterion.h>

Test(my_str_isprintable, test_name)
{
    cr_assert_eq(my_str_isprintable("yuuyesjc-e+543"), 1);
}
