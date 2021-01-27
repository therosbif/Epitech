/*
** EPITECH PROJECT, 2019
** test
** File description:
** count
*/

#include <criterion/criterion.h>

int my_language(char *str);

Test(my_language, test_lang)
{
    cr_assert_eq(my_language("hello all how are you this is unit test"), 0);
    cr_assert_eq(my_language("bonjour tous ceci est un test unitaire"), 1);
    cr_assert_eq(my_language("holaasoytodosestaesunapruebapoounitaria"), 2);
    cr_assert_eq(my_language("Hallo an alle Dies ist ein Unit-Test"), 3);
}
