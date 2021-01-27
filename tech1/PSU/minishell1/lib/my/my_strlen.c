/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** length of str
*/

int my_strlen(char const *str)
{
    int i = 0;

    for ( ; str[i] != '\0' ; i++) {}
    return (i);
}
