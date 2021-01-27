/*
** EPITECH PROJECT, 2019
** test
** File description:
** capital
*/

#include <criterion/criterion.h>

Test(my_strcapitalize, test_name)
{
    cr_assert_str_eq(my_strcapitalize(strdup("H hello")), "H Hello");
}
