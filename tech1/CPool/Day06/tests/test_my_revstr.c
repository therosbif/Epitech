/*
** EPITECH PROJECT, 2019
** test rev
** File description:
** rev
*/

#include <criterion/criterion.h>

Test(my_revstr, test_name)
{
    char dest[6] = "Hello";
    
    my_revstr(dest);
    cr_assert_str_eq(dest, "olleH");
}
