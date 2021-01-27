/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    return ((*str) ? my_strlen(++str) + 1 : 0);
}
