/*
** EPITECH PROJECT, 2019
** test
** File description:
** count
*/

#include <criterion/criterion.h>

int file_exist(char *buff, int ac, char **av);

Test(file_exist, fileexist)
{
    char buff[3000];
    char *av[2];

    av[0] = "cat";
    av[1] = "../tests/test1";
    cr_assert_eq(file_exist(buff, 2, av), 0);
}
