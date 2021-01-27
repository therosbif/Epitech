/*
** EPITECH PROJECT, 2019
** test
** File description:
** count
*/

#include <criterion/criterion.h>

int my_count(char *str, char c);

Test(my_count, test_name)
{
    cr_assert_eq(my_count("hhhh", 'h'), 4);
    cr_assert_eq(my_count("hhafrfghh", 'H'), 4);
    cr_assert_eq(my_count("h", 'h'), 1);
    cr_assert_eq(my_count("adgb", 'h'), 0);
    cr_assert_eq(my_count("", 'h'), 0);
}
