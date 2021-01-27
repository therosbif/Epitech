/*
** EPITECH PROJECT, 2019
** test
** File description:
** count
*/

#include <criterion/criterion.h>

float my_count_alpha(char *str);

Test(my_count_alpha_test, test_count_alpha)
{
    cr_assert_eq(my_count_alpha("hhhh"), 4.0);
    cr_assert_eq(my_count_alpha("eee(eee"), 6.0);
    cr_assert_eq(my_count_alpha("h"), 1.0);
    cr_assert_eq(my_count_alpha("adgb"), 4.0);
    cr_assert_eq(my_count_alpha("azer  dzqq(_'ee"), 10.0);
    cr_assert_eq(my_count_alpha(""), 0);
}
