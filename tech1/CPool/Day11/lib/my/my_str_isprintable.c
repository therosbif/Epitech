/*
** EPITECH PROJECT, 2019
** is printable
** File description:
** is char printable
*/

int my_str_isprintable(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] > 31)
            return (1);
    }
    return (0);
}
