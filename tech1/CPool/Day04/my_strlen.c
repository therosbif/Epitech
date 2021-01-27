/*
** EPITECH PROJECT, 2019
** strlen
** File description:
** length of str
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (i ; str[i] != '\0' ; i++) {}
    return (i);
}
